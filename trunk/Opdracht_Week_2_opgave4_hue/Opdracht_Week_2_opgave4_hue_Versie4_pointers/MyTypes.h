/*----------------------------------------------------*/
/* aut.     :  Patrick & Nikita                       */
/* datum    :  17-02-2014                             */
/* Project  :  Living Colors part 1                   */
/*----------------------------------------------------*/


#ifndef MYTYPES_H    // indien myTypes.h wordt gebruikt dan wordt deze ook mee gecompiled. Conditional inclusion (control the preprocessing)
#define MYTYPES_H
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

const int RGBpinRED   = 9;  //PWM
const int RGBpinGREEN = 10; //PWM
const int RGBpinBLUE  = 11; //PWM
const int LEDpinOut   = 13; // used for testing the toggle function of the push button

const int buttonPin   = 2;  //Input pin for pauze button
const int delayTime   = 75;

#endif MYTYPES_H

