// Motor Driver Pins
#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define enA 10
#define enB 5

// Speed Variables
int M1_Speed = 80;             // Speed of motor 1
int M2_Speed = 80;             // Speed of motor 2
int LeftRotationSpeed = 250;   // Left motor speed for rotation
int RightRotationSpeed = 250;  // Right motor speed for rotation

void setup() {
  // Configure motor driver pins as outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(enA, OUTPUT);  // PWM control for Motor A
  pinMode(enB, OUTPUT);  // PWM control for Motor B

  // Configure sensor pins as inputs
  pinMode(A0, INPUT);    // Left sensor
  pinMode(A1, INPUT);    // Right sensor
}

void loop() {
  // Read sensors
  int LEFT_SENSOR = digitalRead(A0);
  int RIGHT_SENSOR = digitalRead(A1);

  // If both sensors are off (0), move backward
  if (RIGHT_SENSOR == 0 && LEFT_SENSOR == 0) {
    backward();
  }
  // If right sensor is off (0) and left sensor is on (1), turn left
  else if (RIGHT_SENSOR == 0 && LEFT_SENSOR == 1) {
    left();
  }
  // If left sensor is off (0) and right sensor is on (1), turn right
  else if (RIGHT_SENSOR == 1 && LEFT_SENSOR == 0) {
    right();
  }
  // If both sensors are on (1), stop and wait 3 seconds, then move backward
  else if (RIGHT_SENSOR == 1 && LEFT_SENSOR == 1) {
    Stop();
    delay(3000);  // Wait for 3 seconds
    backward();
  }
}

void backward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  analogWrite(enA, M1_Speed);
  analogWrite(enB, M2_Speed);
}

void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(enA, M1_Speed);
  analogWrite(enB, M2_Speed);
}

void right() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Adjust speed for turning
  analogWrite(enA, LeftRotationSpeed);
  analogWrite(enB, RightRotationSpeed);
}

void left() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  // Adjust speed for turning
  analogWrite(enA, LeftRotationSpeed);
  analogWrite(enB, RightRotationSpeed);
}

void Stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  // Motors stop by turning off both motor drivers
}
