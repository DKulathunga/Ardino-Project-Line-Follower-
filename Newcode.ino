#define m1 4  // Right Motor MA1
#define m2 5  // Right Motor MA2
#define m3 2  // Left Motor MB1
#define m4 3  // Left Motor MB2
#define e1 9  // Right Motor Enable Pin EA
#define e2 10 // Left Motor Enable Pin EB

//**********3 Channel IR Sensor Connection**********//
#define ir1 A0  // Left Sensor
#define ir2 A1  // Middle Sensor
#define ir3 A2  // Right Sensor
//*************************************************//

void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  
  Serial.begin(9600); // Start serial communication at 9600 baud rate
}

void loop() {
  // Reading Sensor Values
  int s1 = digitalRead(ir1);  // Left Sensor
  int s2 = digitalRead(ir2);  // Middle Sensor
  int s3 = digitalRead(ir3);  // Right Sensor

  // Print sensor values to the serial monitor
  Serial.print("Left: ");
  Serial.print(s1);
  Serial.print(" | Middle: ");
  Serial.print(s2);
  Serial.print(" | Right: ");
  Serial.println(s3);

  // If only the middle sensor detects the black line
  if (s1 == 1 && s2 == 0 && s3 == 1) {
    // Going forward with full speed
    analogWrite(e1, 255); // Adjust the speed of the motors from 0-255
    analogWrite(e2, 255); // Adjust the speed of the motors from 0-255
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
    Serial.println("Moving Forward");
  }
  
  // If the left sensor detects the black line
  else if (s1 == 0 && s2 == 1 && s3 == 1) {
    // Going right with full speed
    analogWrite(e1, 255); // Adjust the speed of the motors from 0-255
    analogWrite(e2, 255); // Adjust the speed of the motors from 0-255
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
    Serial.println("Turning Right");
  }
  
  // If the right sensor detects the black line
  else if (s1 == 1 && s2 == 1 && s3 == 0) {
    // Going left with full speed
    analogWrite(e1, 255); // Adjust the speed of the motors from 0-255
    analogWrite(e2, 255); // Adjust the speed of the motors from 0-255
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
    Serial.println("Turning Left");
  }
  
  // If middle and left sensors detect the black line
  else if (s1 == 0 && s2 == 0 && s3 == 1) {
    // Going right with full speed
    analogWrite(e1, 255); // Adjust the speed of the motors from 0-255
    analogWrite(e2, 255); // Adjust the speed of the motors from 0-255
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
    Serial.println("Turning Right (Sharp)");
  }
  
  // If middle and right sensors detect the black line
  else if (s1 == 1 && s2 == 0 && s3 == 0) {
    // Going left with full speed
    analogWrite(e1, 255); // Adjust the speed of the motors from 0-255
    analogWrite(e2, 255); // Adjust the speed of the motors from 0-255
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
    Serial.println("Turning Left (Sharp)");
  }

  // If all sensors detect the black line
  else if (s1 == 0 && s2 == 0 && s3 == 0) {
    // Stop
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
    Serial.println("Stopped");
  }
  delay(50);
}
