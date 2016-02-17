#include <math.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);
int sensorPin = A5;

double Thermistor(int RawADC) {
  double Temp;
  Temp = log(10000.0*((1024.0/RawADC-1))); 
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
  Temp = Temp - 273.15;            // Convert Kelvin to Celcius
  Temp = (Temp * 9.0)/ 5.0 + 32.0; // Convert Celcius to Fahrenheit
  return Temp;
}

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,1);
  lcd.write("TEMP: ");
  Serial.begin(9600);
}

void loop() {
  int readVal=analogRead(sensorPin);
  double temp =  Thermistor(readVal);
 
  Serial.println(temp);  // display tempature
  lcd.setCursor(7,1);
  lcd.print(temp);
  delay(500);
}
