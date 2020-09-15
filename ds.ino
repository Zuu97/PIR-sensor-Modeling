#define servo 9

#include <Servo.h>
Servo BigServo;

void setup() {
  BigServo.attach(servo);

}

void loop() {
    BigServo.write(90);
    delay(1000);
    BigServo.write(0);
    delay(1000);
  }
