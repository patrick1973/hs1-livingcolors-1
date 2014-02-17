const int RGBpinRED = 9;
const int RGBpinGREEN = 10;
const int RGBpinBLUE  = 11;
int red,green,blue   = 0;

enum RGBstate
{
  stateSetRedColor,
  stateGoToYellow,
  stateGoToGreen,
  stateGoToCyane,
  stateGoToBLue,
  stateGoToMagenta,
  stateGoToRed
}state;

struct RGB
{
  int red;
  int green;
  int blue;
}RGBcolor;

void setup()
{
  Serial.begin(9600);
  RGBcolor.red = 0;
  RGBcolor.green = 255;
  RGBcolor.blue = 255;
}

void loop()
{
  switch(state)
  {
  case stateSetRedColor:
    Serial.println("stateSetRedColor");
    writeAnalogOutputs(&RGBcolor.red, &RGBcolor.green, &RGBcolor.blue);
    Serial.print(RGBcolor.red); Serial.print("-");Serial.print(RGBcolor.green); Serial.print("-");Serial.println(RGBcolor.blue);Serial.println("\n");
    state = stateGoToYellow;
    break;

  case stateGoToYellow:
    Serial.println("stateGoToYellow");
    for(RGBcolor.green=255; RGBcolor.green>0; RGBcolor.green--)
    {
       writeAnalogOutputs(&RGBcolor.red, &RGBcolor.green, &RGBcolor.blue);
      delay(50);
    }
    Serial.print(RGBcolor.red); Serial.print("-");Serial.print(RGBcolor.green); Serial.print("-");Serial.println(RGBcolor.blue);Serial.println("\n");
    state = stateGoToGreen;
    break;

  case stateGoToGreen:
    Serial.println("stateGoToGreen");
    for(RGBcolor.red=0; RGBcolor.red<255; RGBcolor.red++)
    {
      writeAnalogOutputs(&RGBcolor.red, &RGBcolor.green, &RGBcolor.blue);
      delay(50);
    }
    Serial.print(RGBcolor.red); Serial.print("-");Serial.print(RGBcolor.green); Serial.print("-");Serial.println(RGBcolor.blue);Serial.println("\n");
    state = stateGoToCyane;
    break;

  case stateGoToCyane:
    Serial.println("stateGoToCyane");
    for(RGBcolor.blue=255; RGBcolor.blue>0; RGBcolor.blue--)
    {
       writeAnalogOutputs(&RGBcolor.red, &RGBcolor.green, &RGBcolor.blue);
      delay(50);
    }
    Serial.print(RGBcolor.red); Serial.print("-");Serial.print(RGBcolor.green); Serial.print("-");Serial.println(RGBcolor.blue);Serial.println("\n");
    state = stateGoToBLue;
    break;

  case stateGoToBLue:
    Serial.println("stateGoToBLue");
    for(RGBcolor.green=0; RGBcolor.green<255; RGBcolor.green++)
    {
       writeAnalogOutputs(&RGBcolor.red, &RGBcolor.green, &RGBcolor.blue);
      delay(50);
    }
    Serial.print(RGBcolor.red); Serial.print("-");Serial.print(RGBcolor.green); Serial.print("-");Serial.println(RGBcolor.blue);Serial.println("\n");
    state = stateGoToMagenta;
    break;

  case stateGoToMagenta:
    Serial.println("stateGoToMagenta");
    for(RGBcolor.red=255; RGBcolor.red>0; RGBcolor.red--)
    {
       writeAnalogOutputs(&RGBcolor.red, &RGBcolor.green, &RGBcolor.blue);
      delay(50);
    }
    Serial.print(RGBcolor.red); Serial.print("-");Serial.print(RGBcolor.green); Serial.print("-");Serial.println(RGBcolor.blue);Serial.println("\n");
    state = stateGoToRed;
    break;

  case stateGoToRed:
    Serial.println("stateGoToRed");
    for(RGBcolor.blue=0; RGBcolor.blue<255; RGBcolor.blue++)
    {
      writeAnalogOutputs(&RGBcolor.red, &RGBcolor.green, &RGBcolor.blue);
      delay(50);
    }
    Serial.print(RGBcolor.red); Serial.print("-");Serial.print(RGBcolor.green); Serial.print("-");Serial.println(RGBcolor.blue);Serial.println("\n");
    state = stateGoToYellow;
    break;

  } 
}
void writeAnalogOutputs( int *red, int *green, int *blue)
{
  analogWrite(RGBpinRED,*red);
  analogWrite(RGBpinGREEN,*green);
  analogWrite(RGBpinBLUE,*blue); 
}

