#include <LiquidCrystal.h>  //lcd display library
#include <Servo.h>  //servo operations library

#define bluePin 19
#define redPin 18
#define switchPin 10
#define buzzerPin 8
#define servoPin 9
#define trigPin 12
#define echoPin 11

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);  //lcd to arduino connections
Servo alarm_marker; //servo object declaration

const int brightness_threshold = 400;  //const between day and night mode
const int distance_threshold = 40;  //const to detect movement
int actual_brightness = 0;  //variable for actual brightness

void setup() {
  lcd.begin(16, 2); //lcd type declaration

  alarm_marker.attach(servoPin); //servo to arduino connection

  pinMode(switchPin, INPUT_PULLUP); //tact switch pin
  pinMode(redPin, OUTPUT);  //red diode pin
  pinMode(bluePin, OUTPUT); //blue diode pin
  pinMode(buzzerPin, OUTPUT); //buzzer pin
  pinMode(trigPin, OUTPUT); //trigger distance sensor pin
  pinMode(echoPin, INPUT);  //echo distance sensor pin
}

//bool mode = true;

void loop() {
  actual_brightness = analogRead(A0); //actual read from photoresistor
  if (actual_brightness > brightness_threshold) { //day mode
    day_mode();
    delay(200);
  }
  else {  //night mode
    night_mode();
    delay(200);
  }
}

void day_mode() {
  digitalWrite(bluePin, LOW); //blue diode off
  digitalWrite(redPin, LOW);  //red diode off
  digitalWrite(buzzerPin, LOW);  //buzzer off

  alarm_marker.write(0);  //move servo to sleep position

  int distance = distance_measurement();  //assign actual distance to variable

  lcd.setCursor(0, 0);  //upper line message
  lcd.print("Day mode        ");

  lcd.setCursor(0, 1);  //lower line message
  lcd.print("Brt:");
  lcd.setCursor(4, 1);
  lcd.print(' ');
  lcd.setCursor(5, 1);
  lcd.print(actual_brightness); //display actual brightness
  lcd.setCursor(9, 1);
  lcd.print("Dst:");
  lcd.setCursor(13, 1);
  lcd.print(distance);  //display actual distance
}

void night_mode() {
  alarm_marker.write(90); //move servo to standby position

  digitalWrite(bluePin, HIGH); //blue diode on
  digitalWrite(redPin, LOW);  //red diode off
  digitalWrite(buzzerPin, LOW);  //buzzer off

  int distance = distance_measurement();  //assign actual distance to variable

  if (distance <= distance_threshold) { //when movement is detected
    digitalWrite(bluePin, LOW); //blue diode off
    digitalWrite(redPin, HIGH); //red diode on

    digitalWrite(buzzerPin, HIGH);  //buzzer on

    lcd.setCursor(0, 0);  //upper line message
    lcd.print("WARNING!        ");
    lcd.setCursor(0, 1);  //lower line message
    lcd.print("Move detected   ");
  else {  //no movement
    lcd.setCursor(0, 0);  //upper line message
    lcd.print("Night mode      ");
    lcd.setCursor(0, 1);  //lower line message
    lcd.print("No move detected");
  }
  }
}

int distance_measurement() {
  //distance sensor measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int distance = pulseIn(echoPin, HIGH) / 58;  //distance converted to cm
  return distance;
}
