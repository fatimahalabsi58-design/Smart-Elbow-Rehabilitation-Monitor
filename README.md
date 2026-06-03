Smart Elbow Rehabilitation Monitor

Project Description

The Smart Elbow Rehabilitation Monitor is a low-cost rehabilitation training device designed to monitor elbow flexion and extension exercises. The system uses an HC-SR04 ultrasonic sensor to measure the movement of a foam arm model and provides real-time feedback through an RGB LED, a 16x2 LCD display, and a buzzer.

The project demonstrates how simple electronic components can be used to support physical therapy exercises by monitoring movement range, detecting rehabilitation milestones, and counting completed repetitions.

The prototype simulates elbow rehabilitation after injury or immobilization, helping users perform flexion and extension exercises while receiving immediate visual and audible feedback.

Components

* Arduino Uno
* HC-SR04 Ultrasonic Sensor
* 16x2 LCD Display
* RGB LED Module
* Active Buzzer
* Breadboard
* Jumper Wires
* Yellow Foam Arm Model

System States

The system monitors three movement states during elbow rehabilitation exercises.

1. Flexion OK

* Distance Range: 2–5 cm
* Represents full elbow flexion.
* RGB LED: Green
* LCD Message: “Flexion OK”
* Buzzer: Short beep

2. Middle Range

* Distance Range: 14–25 cm
* Represents the transition phase between flexion and extension.
* RGB LED: Blue
* LCD Message: “Middle Range”

3. Extension OK

* Distance Range: 28.5–28.7 cm
* Represents full elbow extension (~180°).
* RGB LED: Green
* LCD Message: “Extension OK”
* Buzzer: Short beep
* Repetition counter increases after a complete flexion-to-extension cycle.

Calibration

The distance thresholds were experimentally calibrated using the foam arm model.

The ultrasonic sensor measures the distance between the sensor and the moving arm segment. Specific distance ranges were assigned to represent flexion, middle range, and full extension positions.

The extension threshold was calibrated to correspond to approximately 180° elbow extension in the prototype model.

Components Function

HC-SR04 Ultrasonic Sensor

Measures the distance between the sensor and the moving arm model.

LCD Display

Displays rehabilitation status and repetition count.

RGB LED

Provides real-time visual feedback:

* Green = Correct end position
* Blue = Middle range
* Red = Out of range

Active Buzzer

Provides audible confirmation when a target position is reached.

Foam Arm Model

Represents the elbow joint and forearm during rehabilitation exercises.

Wiring Connections

HC-SR04 Ultrasonic Sensor

Sensor Pin	Arduino Pin
VCC	5V
GND	GND
TRIG	D10
ECHO	D11

LCD 16x2 Display

LCD Pin	Arduino Pin
RS	D12
E	D13
D4	D5
D5	D4
D6	D3
D7	D2
V0 (Contrast)	D6
VSS	GND
VDD	5V
RW	GND
A	5V
K	GND

RGB LED Module

RGB Pin	Arduino Pin
R	A0
G	A1
B	A2
GND	GND

Active Buzzer

Buzzer Pin	Arduino Pin
Signal	A3
GND	GND

System Operation

1. The user moves the foam arm through flexion and extension motions.
2. The ultrasonic sensor continuously measures the arm position.
3. The Arduino compares the measured distance to calibrated thresholds.
4. The RGB LED changes color according to the detected movement state.
5. The LCD displays the current rehabilitation status.
6. The buzzer provides audible feedback when target positions are reached.
7. The repetition counter increases after a complete flexion-to-extension cycle.

Features

* Real-time movement monitoring
* Flexion detection
* Extension detection
* Repetition counting
* LCD feedback display
* RGB visual feedback
* Audible feedback
* Low-cost rehabilitation prototype
* Simple and portable design

How to Upload and Run

1. Open Arduino IDE.
2. Connect the Arduino Uno to your computer.
3. Open the project sketch (rehab_monitor.ino).
4. Select:
    * Board: Arduino Uno
    * Correct COM Port
5. Upload the sketch.
6. Power the circuit.
7. Move the foam arm through flexion and extension positions.
8. Observe:
    * LCD status messages
    * RGB LED color changes
    * Repetition counter updates
    * Buzzer notifications
      
Applications

* Physical therapy training
* Elbow rehabilitation exercises
* Biomedical engineering education
* Human movement monitoring
* Rehabilitation device prototyping


Author

Fatimah Jamaan

Biomedical Engineering Student

King Faisal University
