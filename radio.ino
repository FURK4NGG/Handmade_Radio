#include <OLED_I2C.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TEA5767Radio.h> //TEA5767 FM Radio Library (TEA5767 FM Radyo Kütüphanesi)
TEA5767Radio radio = TEA5767Radio();
OLED  myOLED(SDA, SCL, 8);
extern uint8_t SmallFont[];
double frequency = 87.5;
double frequency_pt = 87.5;
int deger = A1;

void setup(){
  Serial.begin(9600);
  Wire.begin();
  myOLED.begin();
  myOLED.setFont(SmallFont);
  pinMode(deger,INPUT);
  Serial.println("Arduino FM Radio ");
}

void loop(){
  int son = analogRead(deger);
  int value_pot = analogRead(A0); // Potentiometer values(Potansiyometre bilgisi)

  // Frequency calculation( Frekans hesaplaması )
  frequency = ((double)value_pot * (108.0 - 87.5)) / 1024.0 + 87.5;
  frequency = ((int)(frequency * 10)) / 10.0;
  String anac = String(frequency);

  // Displaying of frequency change on the screen( Frekans değişikliğinin ekranda gösterilmesi)
  if (son<=180){
    myOLED.clrScr();
    Serial.println("-Frekans-");
    Serial.println(frequency);
    frequency_pt = frequency;
    myOLED.print("-Frekans- ", CENTER, 16);
    myOLED.print(anac, CENTER, 48);
    myOLED.update();
    radio.setFrequency(frequency);
}}