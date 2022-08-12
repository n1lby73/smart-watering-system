#include <LiquidCrystal.h>

int rs = 2;
int en = 3;
int d0 = 4;
int d1 = 5;
int d2 = 6;
int d3 = 7;
int trig = 8;
int echo = 9;
float duration;
float height;
float moisture = A0;
float moisture_percent;
float minimum_moisture_percent;
float moisture_value;
int pump = 10;
float pie = 3.142;
float empty_volume;
float remain_volume;
float total_volume;
float tank_percent;
int alarm = 11;
float heightOfTank = 0;
float minimum_moisture = 0;
float maximum_moisture = 0;
float tankRadius = 0;
int page = 0;
int alarm_dt = 100;
int dt = 300;
int ultrasonic_dt = 10;
int nextBtn_dt = 500;
int longPressDuration = 5;
int increase_btn = 12;
int decrease_btn = 13;
int timed;


LiquidCrystal lcd (rs, en, d0, d1, d2, d3);

void setup() {

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(pump, OUTPUT);
  pinMode(alarm, OUTPUT);
  pinMode(moisture, INPUT);
  pinMode(increase_btn,  INPUT);
  pinMode(decrease_btn, INPUT);

  lcd.begin(16, 2);
  Serial.begin(9600);

  for (int i = 0; i <= 23; i++){

    lcd.setCursor(0,0);
    lcd.scrollDisplayLeft();
    lcd.print(" Automatic Flower Watering System");
    delay(dt);
    lcd.noAutoscroll();  

  }
    
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Your H.O.T: 0.00");
    

  while (page == 0){

    if (digitalRead(increase_btn) == 1){

      delay(dt);
      heightOfTank += 1;

      if (heightOfTank >= 99){

        heightOfTank = 99;

        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Your H.O.T: ");
        lcd.setCursor(12, 0);
        lcd.print(heightOfTank);

      }

      else{

        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Your H.O.T: ");
        lcd.setCursor(12, 0);
        lcd.print(heightOfTank);

      }

    }

    else if (digitalRead(decrease_btn) == 1){

      delay(dt);
      timed = 0;
      
      while((digitalRead(decrease_btn) ==1) && (timed <= 5)){

        timed++;

      }

      if (( timed >= longPressDuration ) && (heightOfTank > 0)){

        page += 1;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Your R.O.T: 0.00");

      }

      else{

        heightOfTank -= 1;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Your H.O.T: ");
        lcd.setCursor(12, 0);

        if (heightOfTank <= 0){

          heightOfTank = 0;
          lcd.print(heightOfTank);

        }

        else{

          lcd.print(heightOfTank);

        }

      }
    }
  }

  while (page == 1){

    if (digitalRead(increase_btn) == 1){

    delay(dt);
    tankRadius += 1;

    if (tankRadius >= 99){

      tankRadius = 99;

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Your R.O.T: ");
      lcd.setCursor(12, 0);
      lcd.print(tankRadius);

    }

    else{

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Your R.O.T: ");
      lcd.setCursor(12, 0);
      lcd.print(tankRadius);

    }
  }

  else if(digitalRead(decrease_btn) == 1){

    delay(dt);
    timed = 0;

    while((digitalRead(decrease_btn) ==1) && (timed <= 5)){

      timed++;
        
    }

    if (( timed >= longPressDuration ) && (tankRadius > 0)){
        
      page += 1;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Max Moisture: 0.00");


    }

    else{

      tankRadius -= 1;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Your R.O.T: ");
      lcd.setCursor(14, 0);

      if(tankRadius <= 0){

        tankRadius = 0;
        lcd.print(tankRadius);

      }

      else{

        lcd.print(tankRadius);

      }
    }
  }
}

  while (page == 2){

    if (digitalRead(increase_btn) == 1){

      delay(dt);
      minimum_moisture += 1;

      if (minimum_moisture >= 99){

        minimum_moisture = 99;

        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Min Moisture: ");
        lcd.setCursor(14, 0);
        lcd.print(minimum_moisture);

      }

      else{

        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Min Moisture: ");
        lcd.setCursor(14, 0);
        lcd.print(minimum_moisture);

      }
    }

    else if(digitalRead(decrease_btn) == 1){

      delay(dt);
      timed = 0;

      while((digitalRead(decrease_btn) ==1) && (timed <= 5)){

        timed++;
        
      }

      if (( timed >= longPressDuration ) && (minimum_moisture > 0)){
        
        page += 1;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Max Moisture: 0");


      }

      else{

        minimum_moisture -= 1;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Min Moisture: ");
        lcd.setCursor(14, 0);

        if(minimum_moisture <= 0){

          minimum_moisture = 0;
          lcd.print(minimum_moisture);

        }

        else{

          lcd.print(minimum_moisture);

        }

      }
    }
  }

  while (page == 3){
    
    if (digitalRead(increase_btn) == 1){

      delay(dt);
      maximum_moisture += 1;

      if (maximum_moisture >= 99){

        maximum_moisture = 99;

        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Max Moisture: ");
        lcd.setCursor(14, 0);
        lcd.print(maximum_moisture);

      }

      else{

        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Max Moisture: ");
        lcd.setCursor(14, 0);
        lcd.print(maximum_moisture);

      }

    }
    
    else if (digitalRead(decrease_btn) == 1){

      delay(dt);
      timed = 0;

      while((digitalRead(decrease_btn) ==1) && (timed <= 5)){

        timed++;
        
      }

      if (( timed >= longPressDuration ) && (maximum_moisture > 0) && (minimum_moisture < maximum_moisture)){

        page += 1;
        lcd.clear();

      }

      else{

        maximum_moisture -= 1;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Max Moisture: ");
        lcd.setCursor(14, 0);

        if (maximum_moisture <= 0){

          maximum_moisture = 0;
          lcd.print(maximum_moisture);

        }


        else{

          lcd.print(maximum_moisture);

        }
      }
    }

  }


  delay(500);
}

void loop() {

  digitalWrite(trig, LOW);
  delayMicroseconds(ultrasonic_dt);

  digitalWrite(trig, HIGH);
  delayMicroseconds(ultrasonic_dt);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  
  moisture_value = analogRead(moisture);

  moisture_percent = (moisture_value / maximum_moisture) * 100.;

  minimum_moisture_percent = (minimum_moisture / maximum_moisture) * 100.;

  Serial.println(minimum_moisture_percent);

  total_volume = (pie * (tankRadius * tankRadius) * heightOfTank);

  remain_volume = (total_volume - (pie * (tankRadius * tankRadius) * 0.0343 *(duration/2)));

  tank_percent = ((remain_volume / total_volume) * 100.);

  if (tank_percent <= 0) {

    tank_percent = 0;

  }

  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");

  lcd.setCursor(0, 1);
  lcd.print("WaterLvl: ");

  if (moisture_percent >= 100) {

    lcd.setCursor(9, 0);
    lcd.print(100);
    lcd.print("%");
    delay(dt);
  }

  else {

    lcd.setCursor(9, 0);
    lcd.print(moisture_percent);
    lcd.print("%");
    delay(dt);

  }

  lcd.setCursor(10, 1);
  lcd.print(tank_percent);
  lcd.print("%");
  delay(50);


  if (moisture_percent <= minimum_moisture_percent) {

    if (tank_percent >= 50) {

      digitalWrite(pump, HIGH);
      digitalWrite(alarm, LOW);

    }

    else {

      digitalWrite(alarm, HIGH);
      delay(alarm_dt);
      digitalWrite(alarm, LOW);
      digitalWrite(pump, LOW);

    }
  }

  else {

    digitalWrite(alarm, LOW);
    digitalWrite(pump, LOW);

  }
}
