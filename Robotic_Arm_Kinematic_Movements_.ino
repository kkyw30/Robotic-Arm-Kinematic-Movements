#include <Servo.h>

Servo xServo;
Servo yServo;
Servo zServo;
Servo clawServo;

int xPos = 0;
int yPos = 0;
int zPos = 0;
int clawPos = 0;

void setup() {
  // assign servo to signal pin numbers
  xServo.attach(3);
  yServo.attach(4);
  zServo.attach(5);
  clawServo.attach(8);

  //Initialize serial port
  Serial.begin(9600);
  //Debug only send serial message to host com port terminal window
  Serial.print("***MeCom Test***.");

}


void loop() {
  // serial in packet pattern
  for (xPos = 0; xPos <= 180; xPos += 1) {
    xServo.write(xPos);
    delay(15);
  }

  for (xPos = 180; xPos >= 0; xPos -= 1) {
    xServo.write(xPos);
    delay(15);
  }

  for (yPos = 0; yPos <= 180; yPos += 1) {
    yServo.write(yPos);
    delay(15);
  }

  for (yPos = 180; yPos >= 0; yPos -= 1) {
    yServo.write(yPos);
    delay(15);
  }

  for (zPos = 0; zPos <= 180; zPos += 1) {
    zServo.write(zPos);
    delay(15);
  }

  for (zPos = 180; zPos >= 0; zPos -= 1) {
    zServo.write(zPos);
    delay(15);
  }

  for (clawPos = 0; clawPos <= 180; clawPos += 1) {
    clawServo.write(clawPos);
    delay(15);
  }

  for (clawPos = 180; clawPos >= 0; clawPos -= 1) {
    clawServo.write(clawPos);
    delay(15);
  }

  while (Serial.available() > 0) {
    xPos = Serial.parseInt();
    yPos = Serial.parseInt();
    zPos = Serial.parseInt();
    clawPos = Serial.parseInt();

    if (Serial.read() == 'x') {
      //Update Servo Positions
      xServo.write(xPos);
      yServo.write(yPos);
      zServo.write(zPos);
      clawServo.write(clawPos);
    }
  }

}
