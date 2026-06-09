IoT Arduino Movement Lamp

This project implements a real-time movement detection system using an Arduino Nano 33 BLE Sense. By leveraging a custom machine learning model trained via Edge Impulse, the device classifies physical movement patterns and provides immediate visual feedback through its built-in RGB LED:

No Light: Idle / No movement detected.
Green Light: Slow up-and-down movement detected.
Red Light: Fast up-and-down movement detected.

Key Features:
Edge AI: The inference model runs locally on the microcontroller, ensuring low latency.
Hardware: Utilizes the Arduino Nano 33 BLE Sense’s built-in accelerometer.
Workflow: Developed using PlatformIO in Visual Studio Code for efficient firmware management and deployment.