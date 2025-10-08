#include <LiquidCrystal.h>  //lcd display library

LiquidCrystal lcd(2,3,4,5,6,7); //defined lcd pins
float seconds = 0;  //float variable to count seconcds
bool timer_on = false;  //boolean for checking timer state

void setup() {
  lcd.begin(16 ,2); //lcd type declaration
  pinMode(8, INPUT_PULLUP); //defined pin for tact switch
  
  //upper line message
  lcd.setCursor(0, 0);  //set cursor at first line
  lcd.print("TIMER"); //print message
  //lower line message
  lcd.setCursor(0, 1);  //set cursor at second line
  lcd.print("Press to start");  //print message

  while(digitalRead(8) == HIGH) delay(25);  //wait for button to be pressed
  timer_on = true;  //timer on mode
  delay(300); //required delay for correct timer work
  lcd.clear();  //clean display

  //upper line message
  lcd.setCursor(0, 0);  //set cursor at first line
  lcd.print("Press to stop"); //print message
  //lower line message
  lcd.setCursor(0, 1);  //set cursor at second line
  lcd.print("0 s");  //print message

  while(timer_on == true) { //repeat until button is pressed
    delay(100);  //0,1 s delay
    seconds += 0.1;  //increase counter value

    //lower line message
    lcd.setCursor(0, 1);  //set cursor at second line
    lcd.print(seconds); //print message
    lcd.print(" s");  //add 's' sign
    if (digitalRead(8) == LOW) timer_on = false;  //change timer_on value when button is pressed
  }

  //final display messages
  lcd.clear();  //clear the display

  //upper line message
  lcd.setCursor(0, 0);  //set cursor at first line
  lcd.print("Measured time:");  //print message
  //lower line message
  lcd.setCursor(0, 1);  //set cursor at second line
  lcd.print(seconds); //print message
  lcd.print(" s");  //add 's' sign
}

//if you want to repeat measurement, just press arduino reset button

void loop() {
}
