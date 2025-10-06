#include <Servo.h>  //servo operations library

Servo servoMotor; //define servo object
int potentiometerValue = 0; //actual potentiometer value
int position = 0;  //transformed to angle potentiometer value

void setup() {
  servoMotor.attach(9); //servo attached to pin 9
}

void loop() {
  potentiometerValue = analogRead(A5);  //assign value to variable
  position = map(potentiometerValue, 0, 1023, 0, 180); //rescaled to an angle
  servoMotor.write(position);  //move servo to setpoint
}
