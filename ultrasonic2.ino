int trig = 3;
int echo = 4;
int travel;
int distance;

void setup() {
  // put your setup code here, to run once:

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trig, LOW); //set transmitter as low initially
  delay(100);
  
  digitalWrite(trig, HIGH); //allow transmitter to send signal fosome time
  delay(100);
  digitalWrite(trig,LOW); //stop transmitter from sending signal
  
  travel = pulseIn(echo, HIGH);
  distance = 0.0343*(travel/2);
  
  Serial.println(distance);

  delay(500);
}
