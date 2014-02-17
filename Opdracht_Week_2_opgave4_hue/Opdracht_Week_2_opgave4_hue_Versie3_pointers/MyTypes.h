
// met typedef maak je alleen een alias aan geen nieuw type
#define DEBUG 0

typedef enum RGBstate
{
  stateSetRedColor,
  stateGoToYellow,
  stateGoToGreen,
  stateGoToCyane,
  stateGoToBLue,
  stateGoToMagenta,
  stateGoToRed
}state;

typedef struct RGB
{
  int red;
  int green;
  int blue;
}RGBcolor;

const int RGBpinRED   = 9;
const int RGBpinGREEN = 10;
const int RGBpinBLUE  = 11;
const int buttonPin   = 2;
const int delayTime   = 75;


