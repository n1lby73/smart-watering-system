#include <LiquidCrystal.h>

int rs = 2;
int en = 3;
int d0 = 4;
int d1 = 5;
int d2 = 6;
int d3 = 7;
int trig = 8;
int echo = 9;
int duration;
int height;
int moisture = A0;
float moisture_percent;
float moisture_value;
float tank_radius = 5.25 * 5.25;
int pump = 10;
float pie = 3.142;
float empty_volume;
float remain_volume;
float tank_percent;
int alarm = 11;
int dt = 200;
int udt = 10; 

LiquidCrystal lcd (rs, en, d0, d1, d2, d3);

void setup() {
  // put your setup code here, to run once:


  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(pump, OUTPUT);
  pinMode(alarm, OUTPUT);
  pinMode(moisture, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {

  digitalWrite(trig, LOW);
  delayMicroseconds(udt);

  digitalWrite(trig, HIGH);
  delayMicroseconds(udt);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  
  height = 0.0343 * (duration / 2);

  moisture_value = analogRead(moisture);

  moisture_percent = (moisture_value/30.) * 100.;

  empty_volume = pie * tank_radius * height;

  Serial.print("empty volume is: ");
  Serial.println(empty_volume);

  remain_volume = 779.41 - empty_volume;

  tank_percent = (remain_volume / 779.41) * 100.;
  

  if (tank_percent <= 0){
    
      tank_percent = 0;
    
    }
  
  lcd.setCursor(0,0);
  lcd.print("Moisture: ");

  lcd.setCursor(0,1);
  lcd.print("WaterLvl: ");

  if (moisture_percent >= 100){
    
    lcd.setCursor(9, 0);
    lcd.print(100);
    lcd.print("%");
    Serial.println(moisture_value);
    delay(dt);
  }

  else{
    
    lcd.setCursor(9, 0);
    lcd.print(moisture_percent);
    lcd.print("%");
    Serial.println(moisture_value);
    delay(dt); 
    
    }
    
  lcd.setCursor(10, 1);
  lcd.print(tank_percent);
  lcd.print("%");
  delay(50);

    
  if (moisture_percent <= 40){

      if (tank_percent >= 50){
        
        digitalWrite(pump, HIGH);
        digitalWrite(alarm, LOW);
    
    }

    else{

      digitalWrite(alarm, HIGH);
      digitalWrite(pump, LOW);
      
      }
    }

    else{
      
        digitalWrite(alarm, LOW);
        digitalWrite(pump, LOW);
      
      }
}
