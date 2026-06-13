# 🦾 Smart Elbow Rehabilitation Monitor

> A low-cost, Arduino-based rehabilitation device for monitoring elbow flexion and extension exercises with real-time multi-modal feedback.

![Platform](https://img.shields.io/badge/Platform-Arduino%20Uno-00979D?style=flat-square&logo=arduino)
![Language](https://img.shields.io/badge/Language-C%2B%2B%20%2F%20Arduino-blue?style=flat-square)
![Domain](https://img.shields.io/badge/Domain-Biomedical%20Engineering-red?style=flat-square)
![Status](https://img.shields.io/badge/Status-Prototype-orange?style=flat-square)
![License](https://img.shields.io/badge/License-MIT-green?style=flat-square)

-----

## 📋 Table of Contents

- [Overview](#overview)
- [Motivation](#motivation)
- [System Architecture](#system-architecture)
- [Hardware Components](#hardware-components)
- [Wiring & Connections](#wiring--connections)
- [System States & Feedback](#system-states--feedback)
- [Calibration](#calibration)
- [Getting Started](#getting-started)
- [Applications](#applications)
- [References](#references)
- [Author](#author)

-----

## Overview

The **Smart Elbow Rehabilitation Monitor** is a low-cost prototype device designed to guide and monitor elbow flexion–extension rehabilitation exercises. Using an HC-SR04 ultrasonic sensor to track arm position, the system provides real-time feedback through three synchronized output channels: an RGB LED, a 16×2 LCD display, and an active buzzer.

The prototype simulates post-injury elbow rehabilitation, helping users correctly perform range-of-motion (ROM) exercises while receiving immediate corrective feedback — without requiring clinical supervision for every session.

-----

## Motivation

Elbow injuries and post-surgical immobilization frequently require structured rehabilitation to restore joint range of motion (ROM). However, access to continuous physiotherapy supervision is limited by cost, geography, and clinic availability [1]. Low-cost embedded systems offer an opportunity to extend rehabilitation support into the home environment [2].

This project explores how fundamental sensor–microcontroller integration can replicate core feedback mechanisms found in clinical rehabilitation devices — at a fraction of the cost.

-----

## System Architecture

```
┌─────────────────────────────────────────────────────────┐
│                      Arduino Uno                        │
│                                                         │
│  HC-SR04          ┌─────────────┐         RGB LED      │
│  Ultrasonic  ───► │  Distance   │ ──────► (Visual)     │
│  Sensor           │  Comparison │                       │
│                   │  & State    │ ──────► LCD Display  │
│  Foam Arm         │  Detection  │         (Status)      │
│  Model            └─────────────┘                       │
│                          │                              │
│                          └──────────► Active Buzzer     │
│                                       (Audible)         │
└─────────────────────────────────────────────────────────┘
```

The system continuously reads distance from the ultrasonic sensor, compares it against experimentally calibrated thresholds, and simultaneously triggers feedback across all three output channels.

-----

## Hardware Components

|Component                |Quantity|Purpose                       |
|-------------------------|--------|------------------------------|
|Arduino Uno (Rev3)       |1       |Microcontroller               |
|HC-SR04 Ultrasonic Sensor|1       |Arm position measurement      |
|16×2 LCD Display         |1       |Status and rep count display  |
|RGB LED Module           |1       |Color-coded visual feedback   |
|Active Buzzer            |1       |Audible milestone confirmation|
|Breadboard               |1       |Prototyping platform          |
|Jumper Wires             |—       |Electrical connections        |
|Yellow Foam Arm Model    |1       |Elbow joint/forearm simulation|

-----

## Wiring & Connections

### HC-SR04 Ultrasonic Sensor

|Sensor Pin|Arduino Pin|
|----------|-----------|
|VCC       |5V         |
|GND       |GND        |
|TRIG      |D10        |
|ECHO      |D11        |

### 16×2 LCD Display

|LCD Pin|Arduino Pin|Notes            |
|-------|-----------|-----------------|
|RS     |D12        |Register select  |
|E      |D13        |Enable           |
|D4     |D5         |Data pin         |
|D5     |D4         |Data pin         |
|D6     |D3         |Data pin         |
|D7     |D2         |Data pin         |
|V0     |D6 (PWM)   |Contrast control |
|VSS    |GND        |Ground           |
|VDD    |5V         |Power            |
|RW     |GND        |Write mode       |
|A      |5V         |Backlight anode  |
|K      |GND        |Backlight cathode|

### RGB LED Module

|RGB Pin|Arduino Pin|
|-------|-----------|
|R      |A0         |
|G      |A1         |
|B      |A2         |
|GND    |GND        |

### Active Buzzer

|Buzzer Pin|Arduino Pin|
|----------|-----------|
|Signal    |A3         |
|GND       |GND        |

-----

## System States & Feedback

The system classifies elbow position into three states based on calibrated distance thresholds:

|State           |Distance Range     |LED Color|LCD Message   |Buzzer    |
|----------------|-------------------|---------|--------------|----------|
|**Flexion OK**  |2 – 5 cm           |🟢 Green  |`Flexion OK`  |Short beep|
|**Middle Range**|14 – 25 cm         |🔵 Blue   |`Middle Range`|Silent    |
|**Extension OK**|28.5 – 28.7 cm     |🟢 Green  |`Extension OK`|Short beep|
|**Out of Range**|All other distances|🔴 Red    |—             |Silent    |

**Repetition Counting:** One repetition is registered after a complete Flexion → Middle → Extension cycle. The rep count is displayed live on the LCD.

-----

## Calibration

Distance thresholds were determined experimentally using the foam arm model:

- The **HC-SR04** measures the distance between the sensor and the moving arm segment.
- Specific distance values were mapped to anatomical positions:
  - **2–5 cm** → Full elbow flexion (~30–45° from anatomical position)
  - **14–25 cm** → Transition / mid-range phase
  - **28.5–28.7 cm** → Full elbow extension (~180°)
- Thresholds should be **recalibrated** if the physical setup changes (arm model dimensions, sensor mounting position, or distance from arm).

> ⚠️ **Note:** These thresholds are specific to this prototype’s physical configuration. Real clinical deployment would require patient-specific calibration and validation.

-----

## Getting Started

### Prerequisites

- [Arduino IDE](https://www.arduino.cc/en/software) (v1.8+ or v2.x)
- USB Type-B cable
- LiquidCrystal library (built into Arduino IDE)

### Installation

1. **Clone this repository:**
   
   ```bash
   git clone https://github.com/fatimah-jamaan/smart-elbow-rehab-monitor.git
   cd smart-elbow-rehab-monitor
   ```
1. **Open the sketch:**
   
   ```
   Arduino IDE → File → Open → rehab_monitor.ino
   ```
1. **Configure board settings:**
- Tools → Board → **Arduino Uno**
- Tools → Port → *Select your COM port*
1. **Upload the sketch:**
- Click **Upload** (→) or press `Ctrl+U`
1. **Run the prototype:**
- Assemble the circuit according to the wiring tables above
- Power the Arduino via USB or external supply
- Move the foam arm through flexion and extension positions
- Observe LCD status, LED color changes, and buzzer feedback

-----

## Applications

- **Physical therapy training** — Guided ROM exercise repetitions
- **Elbow rehabilitation** — Post-injury or post-surgical recovery support
- **Biomedical engineering education** — Sensor integration and embedded systems
- **Low-resource healthcare** — Affordable assistive technology prototyping
- **Human movement monitoring** — Foundational platform for wearable rehab devices

-----

## References

[1] Pew Research Center. (2021). *The state of telehealth and digital health in low-resource settings.* Retrieved from <https://www.pewresearch.org>

[2] Dobkin, B. H. (2017). “A Rehabilitation-Internet-of-Things in the Home to Augment Motor Skills and Exercise Training.” *Neurorehabilitation and Neural Repair*, 31(3), 217–227. <https://doi.org/10.1177/1545968316680490>

[3] Arduino. (2024). *Arduino Uno Rev3 Documentation.* <https://docs.arduino.cc/hardware/uno-rev3>

[4] Cytron Technologies. (2023). *HC-SR04 Ultrasonic Sensor User Guide.* <https://cytron.io/p-hc-sr04>

[5] World Health Organization. (2023). *Rehabilitation 2030: A call for action.* <https://www.who.int/initiatives/rehabilitation-2030>

[6] Krebs, H. I., & Hogan, N. (2006). “Therapeutic Robotics: A Technology Push.” *Proceedings of the IEEE*, 94(9), 1727–1738. <https://doi.org/10.1109/JPROC.2006.880373>

-----

## Author

**Fatimah Jamaan**
Biomedical Engineering Student — King Faisal University, Al-Ahsa, Saudi Arabia
Member, IEEE Student Chapter | Member, SPE Student Chapter

[![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-0A66C2?logo=linkedin)](https://linkedin.com/in/fatimah-jamaan-64678327b)
[![GitHub](https://img.shields.io/badge/GitHub-Follow-181717?logo=github)](https://github.com/fatimahalabsi58-design)

-----

*This project was developed as part of undergraduate biomedical engineering coursework exploring embedded systems applications in rehabilitation medicine.*
