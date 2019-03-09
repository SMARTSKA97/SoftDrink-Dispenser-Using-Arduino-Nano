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
//END OF FUNCTION CALLS

//STARTING OF MAIN SETUP
void setup()  
{
  pinMode(pPin, OUTPUT);                    //PUMP IS IN THE OUTPUT MODE
  pinMode(sPin, INPUT);                     //SMALL SWITCH IS IN THE INPUT MOD
  pinMode(mPin, INPUT);                     //MEDIUM SWITCH IS IN THE INPUT MODE
  pinMode(lPin, INPUT);                     //LARGE SWITCH IS IN THE INPUT MODE
}

//STARTING OF MAIN LOOP
void loop() 
{
  
  if(digitalRead(sPin)==HIGH)    //CHECKING IF SMALL SWITCH IS PRESSED
  {
    pausingOtherPins();
    delay(10000);                   //DELAYING THE PUMP FOR 10 SEC
    digitalWrite(pPin, LOW);        //DEACTIVATING THE PUMP
  }
  if(digitalRead(mPin)==HIGH)    //CHECKING IF MEDIUM SWITCH IS PRESSED
  {
    pausingOtherPins();
    delay(20000);                   //DELAYING THE PUMP FOR 20 SEC
    digitalWrite(pPin, LOW);        //DEACTIVATING THE PUMP.
  }
  if(digitalRead(lPin)==HIGH)    //CHECKING IF LARGE SWITCH IS PRESSED
  {
    pausingOtherPins();
    delay(30000);                   //DELAYING THE PUMP FOR 30 SEC 
    digitalWrite(pPin, LOW);        //DEACTIVATING THE PUMP
  }
}
