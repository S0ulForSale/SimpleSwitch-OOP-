# ESP32 Smart Device Controller (OOP C++)

This project demonstrates the use of core Object-Oriented Programming (OOP) principles in C++ for developing embedded systems based on the ESP32 microcontroller.
The program implements a flexible control system for peripheral devices (LED indicators).

## Key Features:

Abstract Classes:
A base class SmartDevice is created to define a common interface for all device types.

Polymorphism:
Using std::vector<SmartDevice*> allows managing different object types (SimpleLight, StatusIndicator) within a single loop by calling virtual methods.

Encapsulation:
The logic for working with specific pins and device states is hidden inside the classes.

Event Handling:
Physical button press handling is implemented with software debouncing.

## Program Functional Logic:

The program implements a control system for two types of devices using a single physical button.
Thanks to polymorphism, each device has its own unique behavior when receiving a toggle command.

### Device Operation Algorithm:

First Indicator (SimpleLight on GPIO 2):

- Works as a classic toggle switch

- On first button press — turns ON instantly

- On second press — turns OFF instantly

Second Indicator (StatusIndicator on GPIO 4):

- On each button press, it first blinks three times (indicating a mode change)

- After the blinking cycle, it switches to the target state: First press — turns OFF, Second press — turns ON

## Run the Project

You can launch the project here:
https://wokwi.com/projects/458833161596113921

![OOPSwitch](Switch_OOP.gif)
