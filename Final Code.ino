/*

                    ATtiny 85
                      _____
              RESET -|     |- 5V
 Software Serial Rx -|     |- DHT11 Pin (pullup resistor 4.7k)
 Software Serial Tx -|     |-
                GND -|_____|-
*/

//Celsius to Fahrenheit conversion
double Fahrenheit(double celsius)
{
  return 1.8 * celsius + 32;
}

#include <dht11.h>
#include <Tiny4kOLED.h>
#include <TinyWireM.h>

dht11 DHT11;

#define DHT11PIN 3

void setup()
{ 
  oled.begin();
  oled.clear();
  oled.switchFrame();
  delay(1000);
  oled.fill(0x00); //fill screen without color
  //oled.clear();
  //oled.switchFrame();
  //delay(2000);
  //oled.clear();
  //oled.switchFrame();
  delay(1000);
  oled.on();
  oled.setFont(FONT8X16); 
  oled.setCursor(36,0);
  oled.print(F("Welcome"));
  delay(3000);
  oled.clear();
  oled.switchFrame();
  oled.setFont(FONT8X16); // 2 lines of 16 characters exactly fills 128x32
  oled.setCursor(16, 0);
  oled.print(F("The Assembly")); // wrap strings in F() to save RAM!
  oled.setFont(FONT6X8); // 4 lines of 21 characters only fills 126x32
  oled.setCursor(18,2);
  oled.print(F("Weather Station"));
  loading_frame();
  //delay(3000);
  oled.clear();
  oled.switchFrame();
  //delay(1000);
  pinMode(3, INPUT);
  analogReference(INTERNAL);
}

void loop()
{
  //int chk = DHT11.read(DHT11PIN);
  oled.clear(); 
  oled.switchFrame();
  delay(1000);

  oled.setFont(FONT8X16); 
  oled.setCursor(32, 0);
  oled.print("Humidity");
  oled.setCursor(44, 2);
  oled.print((int)DHT11.humidity);
  oled.print(" %");
  delay(3000);
  oled.clear();
  oled.switchFrame();

  oled.setFont(FONT8X16);
  oled.setCursor(4, 0);
  oled.print("Temperature (C)");
  oled.setCursor(44, 2);
  oled.print((int)DHT11.temperature);
  oled.setFont(FONT6X8);
  oled.setCursor(62, 2); //53,4
  oled.print("o ");
  oled.setFont(FONT8X16);
  oled.setCursor(69, 2);
  oled.print("C");
  delay(3000);
  oled.clear();
  oled.switchFrame();

  oled.setFont(FONT8X16);
  oled.setCursor(4, 0);
  oled.print("Temperature (F)");
  oled.setCursor(44, 2);
  oled.print(Fahrenheit(DHT11.temperature));
  oled.setFont(FONT6X8);
  oled.setCursor(86, 2);
  oled.print("o ");
  oled.setFont(FONT8X16);
  oled.setCursor(94, 2);
  oled.print("F");
  delay(3000);
  oled.clear();
  oled.switchFrame();
}


void loading_frame(){
  oled.setFont(FONT6X8);
  oled.setCursor(0, 3);
  oled.print("|->|"); 
  delay(100);
  oled.setCursor(0, 3);
  oled.print("|-->|"); 
  delay(100);
  oled.setCursor(0, 3);
  oled.print("|--->|"); 
  delay(100); 
  oled.setCursor(0, 3);
  oled.print("|---->|"); 
  delay(100);
  oled.setCursor(0, 3);
  oled.print("|----->|"); 
  delay(100);
  oled.setCursor(0, 3);
  oled.print("|------>|"); 
  delay(100) ;  
  oled.setCursor(0, 3);
  oled.print("|------->|"); 
  delay(100); 
  oled.setCursor(0, 3);
  oled.print("|-------->|"); 
  delay(100) ;
  oled.setCursor(0, 3);
  oled.print("|--------->|"); 
  delay(100) ;
  oled.setCursor(0, 3);
  oled.print("|---------->|");  
  delay(100);
  oled.setCursor(0, 3);
  oled.print("|------------>|"); 
  delay(100) ;
  oled.setCursor(0, 3);
  oled.print("|------------->|"); 
  delay(100) ;
  oled.setCursor(0, 3);
  oled.print("|-------------->|"); 
  delay(100);
  oled.setCursor(0, 3);
  oled.print("|---------------->|");  
  delay(100) ;
  oled.setCursor(0, 3);
  oled.print("|----------------->|");  
  delay(100);
  oled.setCursor(0, 3);
  oled.print("|------------------>|"); 
  delay(100);
  oled.setCursor(0, 3);
  for (int i=0;i<5;i++){ 
  oled.setCursor(0, 3);
  oled.print("|-----Completed-----|");  
  delay(100);
  oled.print("|-----         -----|"); 
  delay(100);
  }
  oled.clear();
  oled.switchFrame();
}

