# Car-Arduino-Controller
Components Required
Microcontroller:

Arduino Uno or any similar microcontroller.
Motor Driver:

L298N Motor Driver or any dual-channel H-bridge motor driver to control the two DC motors.
Motors:

Two DC motors for driving the robot.
Sensors:

Two IR Sensors or Line-following Sensors connected to A0 (Left) and A1 (Right).
Power Supply:

A suitable battery pack to power the motors and the Arduino (e.g., 7.4V LiPo or 9V battery).
Connecting Wires:

Jumper wires to connect the components.
Chassis:

A robot chassis to mount the motors, sensors, and the microcontroller.
Circuit Connections
Motor Driver Connections:

Motor A (Left Motor):
in1 → Pin 9
in2 → Pin 8
enA → Pin 10 (PWM)
Motor B (Right Motor):
in3 → Pin 7
in4 → Pin 6
enB → Pin 5 (PWM)
Sensors:

Left Sensor: Signal pin to A0.
Right Sensor: Signal pin to A1.
Both sensors' VCC and GND connected to the Arduino.
Power:

Power the motor driver and Arduino from the same battery (ensure sufficient current).
Let me know if you need a wiring diagram or any further explanation!






