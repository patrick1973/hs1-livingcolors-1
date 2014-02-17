// LET OP, LED werkt geinveteerd. Langste pin is plus. Uigang laag om aan te sturen
// dus bij de analogeWrite wanneer de dutycycle 0 is dan is het led aan. en de duty cycle op 255 is het led uit.

// Hey Nikita,
// een enum is net zo iets als een struct. aleen het vertaald de int waarde in een naampje.
// als je geen waarde er achter zet is de eerste automatisch 0 en de volgende 1 etc.
// je mag er ook waarde achter zetten bijv. uit = 0, geel =1 etc.
// doordat deze namen overeen komen met een getal mag je ze ook in de case gebruiken.

enum RGB     // de naam van de Enum
{
  OFF,       // komt overeen met 0
  YELLOW ,   // komt overeen met 1
  CYAN ,     // komt overeen met 2
  MAGENTA    // komt overeen met 3
}colorState; // de naam van de instantie

const int pinRood = 9;
const int pinGroen = 10;
const int pinBlauw = 11;
int switchCounter = YELLOW;
void setup()
{
}

void loop()
{
  switch(switchCounter)
  {
  case YELLOW: 
    analogWrite(pinRood, 0); 
    analogWrite(pinGroen, 0); 
    analogWrite(pinBlauw, 255);
    delay(1000);
    switchCounter = CYAN;
    break;

  case CYAN:  
    analogWrite(pinRood, 255); 
    analogWrite(pinGroen, 0); 
    analogWrite(pinBlauw, 0);
    delay(1000);
    switchCounter = MAGENTA; 
    break;

  case MAGENTA:
    analogWrite(pinRood, 0); 
    analogWrite(pinGroen, 255); 
    analogWrite(pinBlauw, 0); 
    delay(1000);
    switchCounter = YELLOW;
    break;
  } 
}

