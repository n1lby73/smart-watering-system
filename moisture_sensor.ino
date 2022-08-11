int moisture = A0;
float percent;
float value;

void setup() {
  // put your setup code here, to run once:
  pinMode(moisture, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(moisture);//
//  value = digitalRead(moisture);/

  percent = (value/30.)*100.;

  Serial.println(value);
//  Serial.println(percent);/
  delay(500);
}
