/*----------------------------------------------------*/
/* aut.     :  Patrick & Nikita                       */
/* datum    :  17-02-2014                             */
/* Project  :  Living Colors part 1                   */
/*----------------------------------------------------*/


#ifndef MYTYPES_H    // indien myTypes.h wordt gebruikt dan wordt deze ook mee gecompiled. En maar 1 keer Conditional inclusion (control the preprocessing)
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

const int RGBPINRED   = 9;  //PWM
const int RGBPINGREEN = 10; //PWM
const int RGBPINBLUE  = 11; //PWM
const int LEDPINOUT   = 13; // used for testing the toggle function of the push button

const int BUTTONPIN   = 2;  //Input pin for pauze button
const int DELAYTIME   = 40;

#endif MYTYPES_H

