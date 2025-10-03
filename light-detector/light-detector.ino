#define left A4
#define right A5

int left_photoresistor = 0;  //variables to show values on photoresistors
int right_photoresistor = 0;

void setup() {
  Serial.begin(9600); //set baud rate
  delay(1000);
  pinMode(13, OUTPUT);  //pins for diodes
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  left_photoresistor = analogRead(left);
  right_photoresistor = analogRead(right);

  //loop to show photoresistors values in terminal
  // for (int i = 0; i < 30; i++) {
  // Serial.println();
  // }
  // Serial.println("left:");
  // Serial.println(left_photoresistor);
  // Serial.println("right");
  // Serial.println(right_photoresistor);
  // delay(1000);
  
  int diff = left_photoresistor - right_photoresistor;

  if (diff > 300) {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
  }
  else if (diff <= 300 && diff > 100) {
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
  }
  else if (diff <= 100 && diff >= -100) {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
  }
  else if (diff < -100 && diff >= -300) {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
  }
  else {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
  }
}  