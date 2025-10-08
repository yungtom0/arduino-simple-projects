void setup() {
  pinMode(8, INPUT_PULLUP); //input for tact switch
  randomSeed(analogRead(0));  //to avoid same numbers in every program run
  Serial.begin(9600); //set baud rate
  delay(1000);
}

void loop() {
  Serial.println("Press the button to throw a dice:");  //print message
  while(digitalRead(8) == HIGH) delay(25);  //wait for button to be pressed
  Serial.print("The drawn nubmer is: ");  //print message
  Serial.println(random(1, 7)); //take a random number in range 1 - 6 and print
  delay(1000);
}
