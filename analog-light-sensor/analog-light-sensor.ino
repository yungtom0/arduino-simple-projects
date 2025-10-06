#include <Servo.h>  //servo operations library

Servo servoMotor; //define servo object
byte position = 0; //actual servo position 0-180
int previousPosition = 0;  //previous servo position
//calibration variables
int darkestValue = 0;
int brightestValue = 0;

void setup() {
  pinMode(7, INPUT_PULLUP);
  servoMotor.attach(9);  //servo attached to pin 9
  Serial.begin(9600); //set baud rate
  delay(1000);

  //calibration
  Serial.println("Set lighting to the darkest setting and press the button");
  while (digitalRead(7) == HIGH) delay(25); //wait until the button is pressed
  darkestValue = analogRead(A5);  //assign dakrest value to variable
  delay(1000);
  Serial.println("Set lighting to the brightest setting and press the button");
  while(digitalRead(7) == HIGH) delay(25);  //wait until the button is pressed
  brightestValue = analogRead(A5);  //assign brightest value to variable
  delay(1000);
  Serial.println("Calibration finished");
  delay(1000);
}

void loop() {
  int photoresistorValue = analogRead(A5);  //assign photoresistor value to variable
  position = map(photoresistorValue, brightestValue, darkestValue, 0, 180); //rescale lighting level to servo position

  if (abs(position - previousPosition) > 5) { //avoid noise
    servoMotor.write(position);  //servo movement
    previousPosition = position;  //remember previous position in variable
  }

  Serial.println(photoresistorValue); //print at monitor
  delay(100);
}