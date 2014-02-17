
#include "MyTypes.h" // link header file mee hier in staan de struct en Enum en ook de const variabelen

RGBcolor color;    // maak een instantie aan van de struct
state colorState;  // maak een instantie aan van de Enum

int histRed, histGreen, histBlue, button, buttonState,pauze;

void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin,INPUT);
  color.red = 0;
  color.green = 255;
  color.blue = 255;
}

void loop()
{ 
  switch(colorState)
  {
  case stateSetRedColor:
    Serial.println("stateSetRedColor");
    writeAnalogOutputs(&color);
    colorState = stateGoToYellow;
    break;

  case stateGoToYellow:
    Serial.println("stateGoToYellow");
    for(color.green=255; color.green>0; color.green--)
    {
      writeAnalogOutputs(&color);
      delay(delayTime);
    }    
    colorState = stateGoToGreen;
    break;

  case stateGoToGreen:
    Serial.println("stateGoToGreen");
    for(color.red=0; color.red<255; color.red++)
    {
      writeAnalogOutputs(&color);
      delay(delayTime);
    }
    colorState = stateGoToCyane;
    break;

  case stateGoToCyane:
    Serial.println("stateGoToCyane");
    for(color.blue=255; color.blue>0; color.blue--)
    {
      writeAnalogOutputs(&color);
      delay(delayTime);
    }
    colorState = stateGoToBLue;
    break;

  case stateGoToBLue:
    Serial.println("stateGoToBLue");
    for(color.green=0; color.green<255; color.green++)
    {
      writeAnalogOutputs(&color);
      delay(delayTime);
    }
    colorState = stateGoToMagenta;
    break;

  case stateGoToMagenta:
    Serial.println("stateGoToMagenta");
    for(color.red=255; color.red>0; color.red--)
    {
      writeAnalogOutputs(&color);
      delay(delayTime);
    }
    colorState = stateGoToRed;
    break;

  case stateGoToRed:
    Serial.println("stateGoToRed");
    for(color.blue=0; color.blue<255; color.blue++)
    {
      writeAnalogOutputs(&color);
      delay(delayTime);
    }
    colorState = stateGoToYellow;
    break;
  } 
}
void writeAnalogOutputs( RGBcolor *c) // *c is een verwijzing naar c van het type RGBcolor.
{
  button = digitalRead(buttonPin);  // lees de drukknop in om de loop te pauzeren

    if( button != buttonState)
  {
    delay(delayTime);
    if ( button == HIGH)
    {
      pauze ++;
    }
  }
  buttonState = button;

  if (pauze % 2 == 0)                     // controller of het getal in pauze even is (modulus opperator). 0= even dan worden de act. waarde in de history gekopieerd. (dus normaal bedrijf)
  {
    histRed   = c->red;
    histGreen = c->green;
    histBlue  = c->blue;
    pauze =0;
  }
  else                                //  controleer of het getal in pauze niet even is, 1=oneven dan gebruik de history waarde in de for lussen. (dus pauze bedrijf)
  {
    c->red   = histRed;
    c->green = histGreen;
    c->blue  = histBlue;
  }
  if (DEBUG==1)
  {
    Serial.print("knopje");
    Serial.print(pauze);
    Serial.print("-");
    Serial.print(c->red);
    Serial.print("-");
    Serial.print(c->green);
    Serial.print("-");
    Serial.println(c->blue); 
  }
  analogWrite(RGBpinRED,c->red);
  analogWrite(RGBpinGREEN,c->green);
  analogWrite(RGBpinBLUE,c->blue); 
}



