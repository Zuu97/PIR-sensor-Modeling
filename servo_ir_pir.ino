#define IRinput 4
#define led 12
#define servo 9
#define PIRinput 8

#include <Servo.h>
Servo ServoMotor;

int servo_delay = 60000; // This delay use to turn off the servo
int pir_delay = 10000; // This delay use to turn on led after movement detection by PIR sensor
 
void setup() {
  pinMode(IRinput, INPUT);
  pinMode(led, OUTPUT);

}

void loop() {
  if(digitalRead(IRinput) == 0){
    ServoMotor.attach(servo); // Attach the servo to pin 9 when detect the object by IR sensor
    
    ServoMotor.write(90);  // Turn 90 degrees
    delay(servo_delay); // wait 60 seconds
    ServoMotor.write(0); // turn back to 0 degrees
    delay(1000);
    
    ServoMotor.detach(); // turn off the servo
    
  }

  int pir_val = digitalRead(PIRinput);
  if (pir_val == 1){
    digitalWrite(led, 1);
    delay(pir_delay);
  }
  else{
    digitalWrite(led, 0);
    delay(1000);
  }

}
