/* THIS IS THE CODE FOR SOFTDRINK DISPENSOR USING ARDUINO NANO
 *  WHERE SWITCHES ARE THE PINS SPIN(SMALL PIN), MPIN(MEDIUM PIN) AND LPIN(LARGE PIN)
 *  IT WILL CONROL THE PUMP'S RELAY FOR A DELAY WHERE PPIN IS FOR THE PUMP'S RELAY PIN PIN
 *  THE RELAY IS CONNECTED WITH AN AIR PUMP WHICH WILL BE USED TO POUR THE SOFT DRINK
 *  AND ALL THE PROCESSINGS AND VISUALS ARE SHOWN IN OLED I2C 128X64
 *  FOR THIS OLED I2C DISPLAY WE NEED TO INCLUDE HEADER FILES AND DISPLAY DECLARATION AND STARTING DISPLAY WITH AN ADDRESS 0x3C
 *  MATERIALS REQUIRED:- ARDUINO NANO(1 PC), BREADBOARD(1 PC), TACTILE SWITCH(3 PC), RELAY SPDT(1 PC), AIR PUMP(1 PC), PIPES(2 PC), OLED I2C 128X64 DISPLAY(1 PC), WIRES AND JUMPERS
 */
//INITIALIZATION OF REQUIRED HEADER FILES 
#include<SPI.h>
#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>
//END OF REQUIRED HEADER FILES

//INITIALIZATION OF DISPLAY DECLARATION
Adafruit_SSD1306 display(-1);
//END OF DISPLAY DECLARATION

//INITIALIZATION OF GLOBAL VARIABLES
int pPin=12;    //PUMP'S RELAY PIN
int sPin=2;     //SMALL SWITCH
int mPin=3;     //MEDIUM SWITCH
int lPin=4;     //LARGE SWITCH
//END OF GLOBAL VARIABLES

//FUNCTION CALLS
void pausingOtherPins()       //THIS FUNCTION WILL PAUSE THE OTHER PINS WHILE PUMP'S RELAY IS ON
{
    digitalWrite(sPin, LOW);  //SETTING SMALL PIN DEACTIVATED TILL THE PROCESS IS DONE
    digitalWrite(mPin,LOW);   //SETTING MEDIUM PIN DEACTIVATED TILL THE PROCESS IS DONE
    digitalWrite(lPin,LOW);   //SETTING LARGE PIN DEACTIVATED TILL THE PROCESS IS DONE
    digitalWrite(pPin,HIGH);  //ACTIVATING PUMP
}

void showDisplay(char str[], int s, int clp, int cwp) //THIS FUNCTION WILL DISPLAY THE TEXT WHEN THE SOFTDRINK IS POURED
/*str[] IS THE STRING TO BE DISPLAYED
 * s IS THE TEXT SIZE
 * clp IS THE CURSOR'S LENGTH POSITION
 * cwp IS THE CURSOR'S WIDTH POSITION
 */
{
  display.clearDisplay();                             //CLEARING DISPLAY SCREEN
  display.setTextSize(s);                             //SETTING TEXT SIZE ACCORDING TO THE SIZE PROVIDED DURING CALL
  display.setTextColor(WHITE);                        //SETTING TEXT COLOR
  display.setCursor(clp,cwp);                         //SETTING CURSOR POSITION AS PER PROVIDED
  display.print(str);                                 //DISPLAYING THE STRING PROVIDED
  display.display();                                  //CALLED FOR DISPLAYING IN OLED
}

void lastDisplay()                        //THIS FUNCTION WILL DISPLAY "REMOVE THE GLASS" WHEN THE SOFTDRINK IS ALREADY POURED
{
    display.clearDisplay();               //CLEARING DISPLAY SCREEN
    display.setTextSize(2);               //SETTING TEXT SIZE TO 2
    display.setTextColor(WHITE);          //SETTING TEXT COLOR
    display.setCursor(0,4);               //SETTING CURSOR POSITION TO (0,4) OF OLED
    display.print("Remove the   glass");  //DISPLAYING TEXT
    display.display();                    //CALLED FOR DISPLAYING IN OLED
}
//END OF FUNCTION CALLS

//STARTING OF MAIN SETUP
void setup()  
{
  pinMode(pPin, OUTPUT);                    //PUMP IS IN THE OUTPUT MODE
  pinMode(sPin, INPUT);                     //SMALL SWITCH IS IN THE INPUT MODE
  pinMode(mPin, INPUT);                     //MEDIUM SWITCH IS IN THE INPUT MODE
  pinMode(lPin, INPUT);                     //LARGE SWITCH IS IN THE INPUT MODE
  display.begin(SSD1306_SWITCHCAPVCC,0x3C); //STARTING DISPLAYING WITH STARTING ADDRESS 0x3C
  display.clearDisplay();                   //CLEARING THE DISPLAY
  display.display();                        //CALLED FOR DISPLAYING TEXT IN OLED
}

//STARTING OF MAIN LOOP
void loop() 
{
  
  while(digitalRead(sPin)==HIGH)    //CHECKING IF SMALL SWITCH IS PRESSED
  {
    char sstring[] = "SMALL";       //WANT TO DISPLAY THAT "SMALL" IS PRESSED
    showDisplay(sstring,3.4,23,10); //WILL DISPLAY "SMALL" IN TEXTSIZE = 3.4 AT CURSOR POSITION (23,10)
    pausingOtherPins();             //WILL CALL TO DISABLE OTHER PINS AND ENABLE PUMP'S RELAY
    delay(10000);                   //DELAYING THE PUMP FOR 10 SEC
    digitalWrite(pPin, LOW);        //DEACTIVATING THE PUMP
    lastDisplay();                  //WILL DISPLAY "REMOVE THE GLASS AFTER THE WORK OF PUMP'S RELAY IS DONE
  }
  while(digitalRead(mPin)==HIGH)    //CHECKING IF MEDIUM SWITCH IS PRESSED
  {
    char sstring[]="MEDIUM";        //WANT TO DISPLAY THAT "MEDIUM" IS PRESSED
    showDisplay(sstring,3,15,10);   //WILL DISPLAY "MEDIUM" IN TEXTSIZE = 3 AT CURSOR POSITION (15,10)
    pausingOtherPins();             //WILL CALL TO DISABLE OTHER PINS AND ENABLE PUMP'S RELAY
    delay(20000);                   //DELAYING THE PUMP FOR 20 SEC
    digitalWrite(pPin, LOW);        //DEACTIVATING THE PUMP.
    lastDisplay();                  //WILL DISPLAY "REMOVE THE GLASS AFTER THE WORK OF PUMP'S RELAY IS DONE
  }
  while(digitalRead(lPin)==HIGH)    //CHECKING IF LARGE SWITCH IS PRESSED
  {
    char sstring[]="LARGE";         //WANT TO DISPLAY THAT "LARGE" IS PRESSED
    showDisplay(sstring,3.4,23,10); //WILL DISPLAY "LARGE" IN TEXTSIZE = 3.4 AT CURSOR POSITION (23,10)
    pausingOtherPins();             //WILL CALL TO DISABLE OTHER PINS AND ENABLE PUMP'S RELAY
    delay(30000);                   //DELAYING THE PUMP FOR 30 SEC 
    digitalWrite(pPin, LOW);        //DEACTIVATING THE PUMP
    lastDisplay();                  //WILL DISPLAY "REMOVE THE GLASS AFTER THE WORK OF PUMP'S RELAY IS DONE
  }
}
