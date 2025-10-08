#define echoPin 11
#define trigPin 12

void setup() {
  //signalization didoes
  //blue diodes
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  //yellow diodes
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  //red diodes
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(echoPin, INPUT);  //echo as input - distance read
  pinMode(trigPin, OUTPUT); //trig as output - sending signals 
}

void loop() {
  long distance = measureDistance(); //assign function return to variable
  int diodes = map(distance, 2, 60, 6, 0);  //rescale distance to number of diodes on
  switch (diodes) {
    case 0:
      //all diodes off
      for (int i = 2; i <= 7; i++) digitalWrite(i, LOW);
      break;
    
    case 1:
      //1 diode on, 5 diodes off
      digitalWrite(2, HIGH);
      for (int i = 3; i <= 7; i++) digitalWrite(i, LOW);
      break;

    case 2:
      //2 diode on, 4 diodes off
      for (int i = 2; i <= 3; i++) digitalWrite(i, HIGH);
      for (int i = 4; i <= 7; i++) digitalWrite(i, LOW);
      break;
    
    case 3:
      //3 diode on, 3 diodes off
      for (int i = 2; i <= 4; i++) digitalWrite(i, HIGH);
      for (int i = 5; i <= 7; i++) digitalWrite(i, LOW);
      break;

    case 4:
      //4 diode on, 2 diodes off
      for (int i = 2; i <= 5; i++) digitalWrite(i, HIGH);
      for (int i = 6; i <= 7; i++) digitalWrite(i, LOW);
      break;

    case 5:
      //5 diode on, 1 diodes off
      for (int i = 2; i <= 6; i++) digitalWrite(i, HIGH);
      digitalWrite(7, LOW);
      break;

    case 6:
      //all diodes on
      for (int i = 2; i <= 7; i++) digitalWrite(i, HIGH);
      break;
  }
  delay(200);
}

long measureDistance() {
  //distance measuring function
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long measurement = pulseIn(echoPin, HIGH);
  long distance1 = measurement / 58;  //distance in cm

  return distance1;
}
