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
void setup()
{
  Serial.begin(9600);
  red = 0;
  green = 255;
  blue = 255;
}

void loop()
{
  switch(state)
  {
  case stateSetRedColor:
    Serial.println("stateSetRedColor");
    analogWrite(RGBpinRED,red);
    analogWrite(RGBpinGREEN,green);
    analogWrite(RGBpinBLUE,blue);
    Serial.print(red); Serial.print("-");Serial.print(green); Serial.print("-");Serial.println(blue);
    state = stateGoToYellow;
    break;

  case stateGoToYellow:
    Serial.println("stateGoToYellow");
    for(green=255; green>0; green--)
    {
      analogWrite(RGBpinRED,red);
      analogWrite(RGBpinGREEN,green);
      analogWrite(RGBpinBLUE,blue);
      delay(50);
    }
    Serial.print(red);Serial.print("-");Serial.print(green);Serial.print("-");Serial.println(blue);
    state = stateGoToGreen;
    break;

  case stateGoToGreen:
    Serial.println("stateGoToGreen");
    for(red=0; red<255; red++)
    {
      analogWrite(RGBpinRED,red);
      analogWrite(RGBpinGREEN,green);
      analogWrite(RGBpinBLUE,blue);
      delay(50);
    }
    Serial.print(red);Serial.print("-");Serial.print(green); Serial.print("-");Serial.println(blue);
    state = stateGoToCyane;

    break;

  case stateGoToCyane:
    Serial.println("stateGoToCyane");
    for(blue=255; blue>0; blue--)
    {
      analogWrite(RGBpinRED,red);
      analogWrite(RGBpinGREEN,green);
      analogWrite(RGBpinBLUE,blue); 
      delay(50);
    }
    Serial.print(red);Serial.print("-");Serial.print(green);Serial.print("-");Serial.println(blue);
    state = stateGoToBLue;
    break;

  case stateGoToBLue:
    Serial.println("stateGoToBLue");
    for(green=0; green<255; green++)
    {
      analogWrite(RGBpinRED,red);
      analogWrite(RGBpinGREEN,green);
      analogWrite(RGBpinBLUE,blue);     
      delay(50);
    }
    Serial.print(red);Serial.print("-");Serial.print(green);Serial.print("-"); Serial.println(blue);
    state = stateGoToMagenta;
    break;

  case stateGoToMagenta:
    Serial.println("stateGoToMagenta");
    for(red=255; red>0; red--)
    {
      analogWrite(RGBpinRED,red);
      analogWrite(RGBpinGREEN,green);
      analogWrite(RGBpinBLUE,blue);  
      delay(50);
    }
    Serial.print(red);Serial.print("-");Serial.print(green);Serial.print("-");Serial.println(blue);
    state = stateGoToRed;
    break;

  case stateGoToRed:
    Serial.println("stateGoToRed");
    for(blue=0; blue<255; blue++)
    {
      analogWrite(RGBpinRED,red);
      analogWrite(RGBpinGREEN,green);
      analogWrite(RGBpinBLUE,blue);  
      delay(50);
    }
    Serial.print(red); Serial.print("-");Serial.print(green);Serial.print("-");Serial.println(blue);
    state = stateSetRedColor;
    break;

  } 
}

