#define red 10
#define yellow 9
#define blue 8
#define tswitch 7

//required variables
int potentiometerValue = 0;
String numberStr = "";
int numberInt = 0;
int attempts = 2;
bool gameOver = false;

void setup() {
  pinMode(red, OUTPUT); //outputs for diodes
  pinMode(yellow, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(tswitch, INPUT_PULLUP); //input for tact switch

  digitalWrite(red, LOW); //all diodes off
  digitalWrite(yellow, LOW);
  digitalWrite(blue, LOW);

  Serial.begin(9600); //set baud rate
  delay(1000);

  Serial.println("Ustaw potencjometr i wciśnij przycisk");  //1 set value on potentiometer
  while (digitalRead(tswitch) == HIGH) delay(20); //2 wait for pressing the switch
  potentiometerValue = analogRead(A5);  //3 assign value to variable
}

void loop() {
  if (gameOver) return; //finish game
  Serial.println("Guess the number:");  //game starts
  while (Serial.available() == 0) delay(20);  //wait for the number
  numberStr = Serial.readStringUntil('\n');  //assign number to variable
  numberInt = numberStr.toInt();  //convert string to int
  if (abs(potentiometerValue - numberInt) <= 50) { //if the guess is between +- 50
    digitalWrite(blue, HIGH); //you win
    digitalWrite(yellow, LOW);
    gameOver = true;
    Serial.println("You Win!");
  }
  else if (attempts > 0) {
    digitalWrite(yellow, HIGH); //another try
    attempts--;
    Serial.println("Try again");
  }
  else {
    digitalWrite(yellow, LOW);  //You lose
    digitalWrite(red, HIGH);
    gameOver = true;
    Serial.println("You lose....");
  }
}