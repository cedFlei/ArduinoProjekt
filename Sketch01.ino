// Einbinden des DHT22
#include <DHT.h>                           // Library für DHT Sensor aufgerufen
#define DHTPIN 8                            // DHT Sensor wird aus PIN 9 ausgelesen
#define DHTTYPE DHT22                       // DHT Type wird auf DHT22 festgelegt
DHT dht22(DHTPIN, DHTTYPE);                 // DHTPIN und DHTTYE in dht22 definiert

// Einbinden des LCD
#include "Wire.h"                           // Library für I2C aufgerufen
#include "LiquidCrystal_I2C.h"              // Library für LCD aufgerufen
LiquidCrystal_I2C lcd(0x27,16,2);           // LCD Adresse auf 0x27 gesetzt, 16 Zeichen / 2 Zeilen LCD
// SainSmart IIC/I2C/TWI 1602 Serial LCD Module wie folgt angeschlossen
// LCD GND -> GND ARDUINO
// LCD VCC -> 5V  ARDUINO
// LCD SDA -> A4  ARDUINO
// LCD SCL -> A5  ARDUINO

void setup()
{
  Serial.begin(9600);                       // Serielle Ausgabe beginnen mit 9600baud
  Serial.println("DHT22 Serielle Ausgabe"); // Begrüßung beim Aufruf vom seriellen Monitor
dht22.begin();                              // Auslesen des DHT22 beginnt
lcd.begin();                                 // Initialisierung des LCD                                            
lcd.backlight();                            // LCD Hintergrundbeleuchtung aktivieren
}


void loop()
{
  float t = 0;  //temp auf 0 setzen
  float h = 0; // feuchtigkeit auf 0 setzen
  int i;
  
  for ( i = 0; i <= 5; i++) {               // fünf mal messen und die Summe bilden zu können
     t = dht22.readTemperature()+ t;        // Die Temperatur wird vom DHT22 ausgelesen, Wert in "t" schreiben
     h = dht22.readHumidity()+ h;           // Die Luftfeuchte wird vom DHT22 ausgelesen, Wert in "h" schreiben
    delay(1000);
  }
  t = t/i;                                   // Die Summe Bilden
  h = h/i;                                   // Die Summe Bilden
  Serial.print("Temperatur: ");             // Ausgabe im Seriellen Monitor
  Serial.print(t);                          // Ausgabe im Seriellen Monitor
  Serial.print(" C\t");                     // Ausgabe im Seriellen Monitor  
  Serial.print("Luftfeuchte: ");            // Ausgabe im Seriellen Monitor
  Serial.print(h);                          // Ausgabe im Seriellen Monitor
  Serial.println(" %");                     // Ausgabe im Seriellen Monitor

  
lcd.setCursor(0, 0);                       // Anfang auf Stelle 0, Zeile 0 setzen
lcd.print("Temp. :");                      // Temp. : auf LCD ausgeben
lcd.setCursor(9, 0);                       // Anfang auf Stelle 9, Zeile 0 setzen
lcd.print(t);                              // Wert aus "t" ausgeben (Temperatur)
lcd.setCursor(15, 0);                      // Anfang auf Stelle 15, Zeile 0 setzen
lcd.print("C");                            // C auf LCD ausgeben
lcd.setCursor(0, 1);                       // Anfang auf Stelle 0, Zeile 1 setzen
lcd.print("Luftf.:");                      // Luft.: auf LCD ausgeben
lcd.setCursor(9, 1);                       // Anfang auf Stelle 9, Zeile 1 setzen
lcd.print(h);                              // Wert aus "h" ausgeben (Luftfeuchtigkeit)
lcd.setCursor(15, 1);                      // Anfang auf Stelle 15, Zeile 1 setzen
lcd.print("%");                            // % auf LCD ausgeben

}
