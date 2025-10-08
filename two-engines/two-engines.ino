//diodes symbolise real motors and their speed and direction

void setup() {
  pinMode(6, OUTPUT); //motor 1 - PWM signal
  pinMode(11, OUTPUT); //motor 2 - PWM signal
  digitalWrite(6, HIGH);  //high state on pin 6
  digitalWrite(11, HIGH);  //high state on pin 11

  //motor 1 direction control signals
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  //motor 2 direction control signals
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  //both motors rotate left
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  delay(2000);  //wait 2 seconds

  //motor 1 rotate right, motor 2 rotate left
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  delay(2000);  //wait 2 seconds

  //motor 1 rotate left, motor 2 rotate right
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  delay(2000);  //wait 2 seconds

  //both motors rotate right
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  delay(2000);  //wait 2 seconds
}
