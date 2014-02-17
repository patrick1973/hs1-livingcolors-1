
#include "MyTypes.h"

RGBcolor color;
state colorState;

int RGBpinRED = 9;
int RGBpinGREEN = 10;
int RGBpinBLUE  = 11;

void setup()
{
  Serial.begin(9600);
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
    //writeAnalogOutputs(&RGBcolor.red, &RGBcolor.green, &RGBcolor.blue);
    Serial.print(color.red); Serial.print("-");Serial.print(color.green); Serial.print("-");Serial.println(color.blue);Serial.println("\n");
    colorState = stateGoToYellow;
    break;

  case stateGoToYellow:
    Serial.println("stateGoToYellow");
    for(color.green=255; color.green>0; color.green--)
    {
      //writeAnalogOutputs(&color.red, &color.green, &color.blue);
      delay(50);
    }
    Serial.print(color.red); Serial.print("-");Serial.print(color.green); Serial.print("-");Serial.println(color.blue);Serial.println("\n");
    colorState = stateGoToGreen;
    break;

  case stateGoToGreen:
    Serial.println("stateGoToGreen");
    for(color.red=0; color.red<255; color.red++)
    {
      //writeAnalogOutputs(&color.red, &color.green, &color.blue);
      delay(50);
    }
    Serial.print(color.red); Serial.print("-");Serial.print(color.green); Serial.print("-");Serial.println(color.blue);Serial.println("\n");
    colorState = stateGoToCyane;
    break;

  case stateGoToCyane:
    Serial.println("stateGoToCyane");
    for(color.blue=255; color.blue>0; color.blue--)
    {
       //writeAnalogOutputs(&color.red, &color.green, &color.blue);
      delay(50);
    }
    Serial.print(color.red); Serial.print("-");Serial.print(color.green); Serial.print("-");Serial.println(color.blue);Serial.println("\n");
    colorState = stateGoToBLue;
    break;

  case stateGoToBLue:
    Serial.println("stateGoToBLue");
    for(color.green=0; color.green<255; color.green++)
    {
       //writeAnalogOutputs(&color.red, &color.green, &color.blue);
      delay(50);
    }
    Serial.print(color.red); Serial.print("-");Serial.print(color.green); Serial.print("-");Serial.println(color.blue);Serial.println("\n");
    colorState = stateGoToMagenta;
    break;

  case stateGoToMagenta:
    Serial.println("stateGoToMagenta");
    for(color.red=255; color.red>0; color.red--)
    {
       //writeAnalogOutputs(&color.red, &color.green, &color.blue);
      delay(50);
    }
    Serial.print(color.red); Serial.print("-");Serial.print(color.green); Serial.print("-");Serial.println(color.blue);Serial.println("\n");
    colorState = stateGoToRed;
    break;

  case stateGoToRed:
    Serial.println("stateGoToRed");
    for(color.blue=0; color.blue<255; color.blue++)
    {
      //writeAnalogOutputs(&color.red, &color.green, &color.blue);
      delay(50);
    }
    Serial.print(color.red); Serial.print("-");Serial.print(color.green); Serial.print("-");Serial.println(color.blue);Serial.println("\n");
    colorState = stateGoToYellow;
    break;

  } 
}
//void writeAnalogOutputs( color *c)
//{
  //analogWrite(RGBpinRED,c->red);
  //analogWrite(RGBpinGREEN,c->green);
  //analogWrite(RGBpinBLUE,c->blue); 
//}

