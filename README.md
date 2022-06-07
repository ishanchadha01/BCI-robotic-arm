# BCI-robotic-arm


## Background

Robots are becoming increasingly ubiquitous in our society, ranging from personal use applications like skateboards to industrial-scale warehouse machines. When researching various types of robots, we encountered two modes of thinking relating to mechanical design: designs that automate tasks usually performed by humans and designs that aid humans with tasks in their daily life. 

At first, we thought of tackling the former train of thought, looking to design a robotic arm that could be found in a warehouse to perform tasks autonomously. However, whether we follow the former or the latter train of thought, robots are designed to either perform tasks that humans previously performed or aid humans with tasks they currently perform, so creating a robot that mirrors human capabilities makes intuitive sense. Thus, we decided to create a robotic hand controlled by a human hand. This could be applied to both performing tasks to help humans or training completely autonomous robots to perform tasks similar to humans.

Additive manufacturing is a groundbreaking technology that changes how robots are designed. In order to show that the process of creating robots can be completely automated, the entirety of the robotic hand, other than the wires and motors, was 3D printed. 3D printed hands also scale up to more extensive applications, which further fits the problem we are attempting to solve. Since the most logical method of controlling a robotic hand is with a human hand, we thought of designing a glove that can control the robotic hand. Flex sensors are variable resistors shaped like a thin strip of paper that can relay information about how much the sensor is being bent; hence, this sensor was employed to detect how much each finger bent.
In addition to using flex sensors, Brain-computer interfaces (BCI) is an up-and-coming technology used to read signals from the brain to perform specific tasks. BCIs are a technology yet to be widely employed by ordinary people due to noisy readings given by brain wave (EEG) sensors and the expense of setting up readings. We thought to attempt to incorporate EEG readings from a BCI sensor so that we could show that a robotic hand could not only be controlled by a human hand but also by brain waves, taking a step further into the future of robotic control. SSVEP is a method used in the BCI community to detect differences in visual patterns. Electrodes placed over someone's occipital lobe provide different readings when the user observes different frequencies of flashing light, which can be used to provide different digital control signals.


## Design

The hardware can be split into three components: the robotic hand, the glove controlling the hand, and hardware that was not included due to its experimental nature. The software was split between the two Arduino modules.

### Robotic Hand

The robotic hand was decomposed into two primary parts: the hand and the forearm. These parts were 3D printed using Ultimaker 3D printers around Georgia Tech's campus. 
The forearm was used as a motor casing, housing all five finger control motors and having an open back where the wires could easily be manipulated. The shaft of each of the five motors protruded out of the front of the motor casing, allowing the motors to be wired to the fingers. A sixth motor connected the hand and the forearm, serving as a wrist joint for rotational motion in the horizontal plane. The entire hand was placed on this wrist joint, rotating up to 45 degrees to demonstrate wrist flexion. 

The hand consisted of palm and finger joints for each joint found in a normal human hand: two thumb joints, three index finger joints, three middle finger joints, three ring finger joints, and two pinky finger joints. Each joint functioned off of a wheel-and-axle mechanism, where there were two axles and a pole that ran through the joints for each one. Each finger contained either one or multiple holes for a cable to run through. The fingers have a divet with a hook for cables to be tied to. These cables ran down each finger and connected to one of the five motors protruding from the motor encasing. For the finger to spring back into place after the motor was returned to its non-flexed position, two to three rubber bands were attached to the back of each finger, depending on the number of joints that the respective finger contained.

Each of the motors was an MG996R servo motor, and the default six-wing attachments for each Servo were used for the thumb, index, ring, and pinky fingers. For the middle finger, the default circular servo attachment was used to conserve space. The ground pin for each motor was attached in series to the ground, and the power pin of each motor was attached in series to a 6V and 2.5A power supply. Each PWM pin was attached to a separate PWM port on an Arduino Uno.

The Arduino Uno was connected to a Hiltego HC-05 Bluetooth module to communicate with the glove. The transmitter of the Bluetooth module was connected to the receiver of the Arduino Uno and vice versa. The VCC of the Bluetooth module did not connect directly to the previously described power supply due to the high and inconsistent voltages, so a 1000uF, 50V rated capacitor and a voltage divider of 1KΩ resistor and a 2KΩ resistor were connected to the Bluetooth module to stabilize and facilitate the connection. 

### Glove Control

An AdaFruit short flex sensor was attached to the back of each finger on a black glove. Each flex sensor (whose resistance ranged between 25kΩ and 100kΩ) and a 6.8KΩ resistor was wired in parallel to the 6V power supply of an Arduino Mega 2560. The voltage drop across each of these parallel components was 6V, so as each flex sensor was bent, the amount of resistance provided by the flex sensor decreased relative to the 6.8K resistor. A wire was placed between the resistor and flex sensor in each parallel component, meaning that each sensor's change in voltage drop across the flex sensor could be measured. More specifically, each wire was connected to an analog port on the Arduino, ports A0 through A4.
Alongside the five finger measurements, a gyroscope measurement was also sent to the Arduino. The serial clock and serial data pins on the GY521 gyroscope module were connected to their respective ports on the Arduino and the power and ground pins on the gyroscope. The Z-measurement on the gyroscope gave information about whether the glove is face-down or not since the gyroscope was taped to the palm of the glove.

A Hiltego HC-05 Bluetooth module was connected to the glove, acting as the master module, while the robotic hand acted as the slave module. The transmitter of the Bluetooth module was connected to the receiver of the Arduino Uno and vice versa. The VCC of the Bluetooth module did not connect directly to the previously described Arduino power due to possibly high and inconsistent voltages, so a 1000uF, 50V rated capacitor and a voltage divider of 1KΩ resistor and a 2KΩ resistor was connected to the Bluetooth module to facilitate the connection. 

### Software

In order to send and receive voltage drops read by the glove as well as the gyroscope reading, an array of six strings (one for each of the finger motors and one for the wrist motor) of constrained voltage drops was passed as a serial message from the master Bluetooth module to the slave Bluetooth module. The values were constrained between 0 and 999 to exclude random spikes. In the slave module, each of the first five values was constrained to specific ranges determined as a minimum and maximum voltage drop for each flex sensor and then mapped to a rotation angle from 0 to 180 degrees for each servo motor for proportional control. The gyroscope reading was mapped from -70 to 70 to an angle of 0 to 45 for wrist rotation. All the code was written in Arduino C++ using the Arduino IDE 2.0.


## Challenges and Future Work

Multiple brain-computer interfaces were tested but could not be implemented. First, the NeuroSky TGAT-1 chip from an old MindFlex headset was wired to an Arduino Uno, but unfortunately, the readings from the provided electrodes and chip were too noisy to be used. Alongside this, we collaborated with Georgia Tech's BrainLab to experiment with their electrode caps. At first, the electrodes could not provide consistent readings, but then members of the BrainLab constructed an amplifier circuit for each electrode. However, the readings using this setup, paired with an OpenBCI Cyton biosensing board, were still very noisy. Multiple SSVEP experiments were attempted but failed.

Other minor shortcomings in hardware occurred, as well. An external power supply was supposed to be connected to the glove, but the linear regulator used to convert 9V to 5V did not work in the live demonstration, so the glove was just powered by a laptop. The thumb was not connected via cable to its respective motor housed in the forearm motor casing due to the thumb requiring a horizontal range of motion and the attachment being utilized for movement breaking preceding the live demonstration. The flex sensors on the fingers are also loose due to the glue and tape wearing out. A more permanent solution would be to stitch a pocket in the glove and place them there.

In the future, we plan to attend more BrainLab meetings and experiment with different ways to control a robotic hand and make the hand more functional, and fix the shortcomings already addressed. Then, we aim to target one specific application of our work, such as prosthetic design, and tailor our project to that application.



