#include <DHT.h>
#include <Wire.h>               // Include I2C bus library
#include <LiquidCrystal_I2C.h>  // Include LCD-I2C bus library
#define DHTPIN 2               //pin connect DHT
#define DHTTYPE DHT11           //if use DHT11 edit to "DHT11"
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); 

int buzzer = 10;
int smokeA0 = A0;
int sensorThres = 10;


void setup()
{
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  dht.begin();
  lcd.init();                  // Start LCD operation
  lcd.backlight();              // Turn on backlight of LCD
  lcd.setCursor(0, 0);          // Set LCD home position
  lcd.print("Humidity=");       // Print Humidity message
  lcd.setCursor(0, 1);          // Set LCD home position of 2nd line
  lcd.print("Temp=");           // Print Temperature message  
}
void loop(){
  int analogSensor = analogRead(smokeA0);

 if (analogSensor > sensorThres )
  {
    tone(buzzer, 1000, 200);
  }
  else
  {
    noTone(buzzer);
  }
  
{
  delay(2500);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  lcd.setCursor(10, 0);          
  lcd.print(h + String("%"));       // Show humidity value in %RH
  lcd.setCursor(6, 1);            
  lcd.print(t + String("C"));        // Show temperature value in Celcuis   
  delay(2500);
}
}

