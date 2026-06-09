# IoT Arduino Movement Lamp

## Overview

This project uses an Arduino Nano 33 BLE Sense and a machine learning model trained with Edge Impulse to detect movement patterns in real time.

The built-in RGB LED provides visual feedback based on the detected movement:

* **No Light** – No movement detected
* **Green Light** – Slow up-and-down movement
* **Red Light** – Fast up-and-down movement

## Hardware

* Arduino Nano 33 BLE Sense
* Built-in accelerometer
* Built-in RGB LED

## Development

The machine learning model was trained using Edge Impulse and exported for Arduino deployment. The firmware was developed in Visual Studio Code using PlatformIO.

## Technologies

* Arduino Nano 33 BLE Sense
* Edge Impulse
* PlatformIO
* C++

## License

MIT License
