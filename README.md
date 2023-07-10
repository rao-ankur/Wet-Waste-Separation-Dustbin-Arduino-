# Wet Waste Separation Dustbin Arduino Code
This repository contains the Arduino code for a wet waste separation dustbin. The code enables the dustbin to detect and separate wet waste from dry waste using various sensors and servo motor.

## Table of Contents
1. [Introduction](#general-info)
2. [Hardware-Requirements](#Hardware-Requirements)
3. [Installation](#installation)
4. [Usage](#Usage)
5. [Contributing](#Contributing)

## Introduction
The wet waste separation dustbin is designed to automate the process of segregating wet waste from dry waste. The Arduino code provided in this repository allows the dustbin to detect the type of waste and open the respective compartment for disposal. The code is modular and can be customized based on your specific hardware setup and requirements.

## Hardware-Requirements
To use this Arduino code, you will need the following components:

1. Arduino board (e.g., Arduino Uno)
2. Ultrasonic sensor (for measuring the distance of waste)
3. Moisture sensor (for detecting wet waste)
4. Servo motor (to open/close the compartments)
5. IR sensor (to detect waste has been placed in dustbin)
6. LED lights (optional, for visual indication)
7. Make sure you have connected the hardware components correctly before running the code.

## Installation
To get started with the wet waste separation dustbin, follow these steps:

1. Clone or download this repository to your local machine.
2. Connect the required hardware components to your Arduino board as per your specific setup.
3. Open the wet_waste_separation.ino file in the Arduino IDE.
4. For information on installing libraries, see: http://www.arduino.cc/en/Guide/Libraries
5. Upload the code to your Arduino board.

## Usage 
Once you have uploaded the code to your Arduino board, the wet waste separation dustbin will be ready for use. Here's how you can use it:

1. Power on the Arduino board and ensure that all the hardware components are properly connected.
2. Place the waste in front of the IR sensor.
3. The IR sensor will measure the distance and determine if there is waste in front of it.
4. If waste is detected, the moisture sensor will analyze the waste to determine if it is wet or dry.
5. Based on the analysis, the servo motor will open the respective compartment for waste disposal.
6. Dispose of the waste into the open compartment.
7. The servo motor will automatically close the compartment once the waste has been deposited.
8. Repeat the process for subsequent waste items.
9. If any of the compartment is filled above it max limit ultrasonic sensor(placed in each compartment) will detect and stop from further waste disposal and triggers the LED or buzzer to unfill the compartment. 

## Contributing
Contributions to this repository are welcome. If you have any improvements, bug fixes, or new features to propose, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and ensure the code remains functional.
4. Commit your changes and push the branch to your forked repository.
5. Submit a pull request with a clear description of your changes.