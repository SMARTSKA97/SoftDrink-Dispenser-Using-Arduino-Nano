/* THIS IS THE CODE FOR SOFTDRINK DISPENSOR
 *  WHERE SWITCHES ARE THE PINS SPIN(SMALL PIN), MPIN(MEDIUM PIN) AND LPIN(LARGE PIN)
 *  IT WILL CONROL THE PUMP FOR A DELAY WHERE PPIN IS FOR THE PUMP PIN
 *  AND ALL THE PROCESSINGS ARE SHOWN IN OLED I2C 128X64
 */
 
#include<SPI.h>
#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>
Adafruit_SSD1306 display(-1);



int pPin=12;    //PUMP PIN
int sPin=2;     //SMALL SWITCH
int mPin=3;     //MEDIUM SWITCH
int lPin=4;     //LARGE SWITCH
int ledPin=A4;  //LED I2C PIN

void pausingOtherPins()
{
    display.clearDisplay();   //CLEARING DISPLAY SCREEN
    digitalWrite(sPin, LOW);  //SETTING SMALL PIN DEACTIVATED TILL THE PROCESS IS DONE
    digitalWrite(mPin,LOW);   //SETTING MEDIUM PIN DEACTIVATED TILL THE PROCESS IS DONE
    digitalWrite(lPin,LOW);   //SETTING LARGE PIN DEACTIVATED TILL THE PROCESS IS DONE
    digitalWrite(pPin,HIGH);  //ACTIVATING PUMP
}

void setup()  
{
  pinMode(pPin, OUTPUT);  //PUMP IS IN THE OUTPUT MODE
  pinMode(sPin, INPUT);   //SMALL SWITCH IS IN THE INPUT MODE
  pinMode(mPin, INPUT);   //MEDIUM SWITCH IS IN THE INPUT MODE
  pinMode(lPin, INPUT);   //LARGE SWITCH IS IN THE INPUT MODE
  display.begin(SSD1306_SWITCHCAPVCC,0x3C);
  display.clearDisplay();
  display.display();
}

void loop() 
{
  
  while(digitalRead(sPin)==HIGH)  //CHECKING IF SMALL SWITCH IS PRESSED
  {
    display.clearDisplay();
    display.setTextSize(3.4);
    display.setTextColor(WHITE);
    display.setCursor(23,10);
    display.print("SMALL");
    display.display();
    pausingOtherPins();
    delay(10000);             //DELAYING THE PUMP FOR 1 SEC
    display.clearDisplay();//CLEARING DISPLAY SCREEN
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,4);
    display.print("Remove the   glass");
    display.display();
    digitalWrite(pPin, LOW);  //DEACTIVATING THE PUMP
  }
  while(digitalRead(mPin)==HIGH)  //CHECKING IF MEDIUM SWITCH IS PRESSED
  {
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(15,10);
    display.print("MEDIUM");
    display.display();
    pausingOtherPins();
    delay(20000);          //DELAYING THE PUMP FOR 2 SEC
    display.clearDisplay();//CLEARING DISPLAY SCREEN
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,4);
    display.print("Remove the   glass");
    display.display();
    digitalWrite(pPin, LOW);    //DEACTIVATING THE PUMP
  }
  while(digitalRead(lPin)==HIGH)  //CHECKING IF LARGE SWITCH IS PRESSED
  {
    display.clearDisplay();
    display.setTextSize(3.4);
    display.setTextColor(WHITE);
    display.setCursor(23,10);
    display.print("LARGE");
    display.display();
    pausingOtherPins();
    delay(30000);          //DELAYING THE PUMP FOR 3 SEC
    display.clearDisplay();   //CLEARING DISPLAY SCREEN
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,4);
    display.println("Remove the  glass");
    display.display();
    digitalWrite(pPin, LOW);    //DEACTIVATING THE PUMP
  }
}
