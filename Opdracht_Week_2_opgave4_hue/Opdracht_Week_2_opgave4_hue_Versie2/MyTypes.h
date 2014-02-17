
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


