#include <Servo.h>  //servo operations library

String position = ""; //string variable to read message from UART
int position_int = 0; //int variable to convert message to int
Servo servo_motor;  //define servo object


void setup() {
  servo_motor.attach(9);  //servo motor plugged to pin 9
  Serial.begin(9600); //set baud rate
  delay(2000);
  servo_motor.write(0); //set servo to default position
}

void loop() {
  Serial.println("\n\n\n\n\n\n\n\n\n\n\n\n\n"); //clear monitor
  Serial.println("Give servo position in the range 0 - 180:");  //print message to serial monitor
  while (Serial.available() == 0) delay(25);  //wait until position given
  position = Serial.readStringUntil('\n');  //assign position to variable
  position_int = position.toInt();  //transform string to int
  if (position_int >= 0 && position_int <= 180) { //if position is between 0 and 180
    servo_motor.write(position_int);  //move servo
  }
  else {
    Serial.println("Wrong position"); //print error message
    delay(2000);
  }
}
