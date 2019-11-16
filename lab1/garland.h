#include "RGBcolor.h"
#define first_R_OUT 2
#define first_G_OUT 3
#define first_B_OUT 4

#define second_R_OUT 5
#define second_G_OUT 6
#define second_B_OUT 7

#define third_R_OUT 8
#define third_G_OUT 9
#define third_B_OUT 10

// три светодиода
int firstLed[] = {first_R_OUT, first_G_OUT, first_B_OUT};
int secondLed[] = {second_R_OUT, second_G_OUT, second_B_OUT};
int thirdLed[] = {third_R_OUT, third_G_OUT, third_B_OUT};


int* leds[] = {firstLed, secondLed, thirdLed};

// colors
RGBColor colorRed(255, 0, 0);
RGBColor colorGreen(0, 255, 0);
RGBColor colorBlue(0, 0, 255);
RGBColor colorWhite(255, 255, 255);
RGBColor colorPurple(170, 0, 255);
RGBColor colorYellow(255, 210, 0);
RGBColor colorOrange(240, 69, 0);
RGBColor colorBlack(0,0,0);

class Garland
{
public:
    Garland()
    {
      durations = 0;
      modeLength = 0;
      stateNumber = 0;
      states[modeLength];
    }

    void set_mode(String *_states, int *_durations, int _modeLength)
    {
      //Serial.println("Pressed");
      states = _states;
      durations = _durations;
      modeLength = _modeLength;
      stateNumber = 0;
    }

    void set_next_state()
    {
      for (int i = 0; i < 3; i++)
        color_handler(i);
      stateNumber += 1;
      //  Serial.println("Set");
    }

    void color_handler(int ledNum)
    {
      int* currentLed = leds[ledNum];
      
      switch (states[stateNumber % modeLength][ledNum]) { // берем состояние циклически и смотрим цвет
        case 'R':
          set_rgb_led(currentLed, colorRed);
          break;
        case 'G':
          set_rgb_led(currentLed, colorGreen);
          break;
        case 'B':
          set_rgb_led(currentLed, colorBlue);
          break;
        case '_':
          set_rgb_led(currentLed, colorBlack);
          break;
        case 'O':
          set_rgb_led(currentLed, colorOrange);
          break;
        case 'Y':
          set_rgb_led(currentLed, colorYellow);
          break;
        case 'W':
          set_rgb_led(currentLed, colorWhite);
          break;
        case 'P':
          set_rgb_led(currentLed, colorPurple);
          break;
      }
    }

    int get_current_duration()
    {
       return durations[stateNumber % modeLength];
    }
      
    void set_rgb_led(int led[], RGBColor rgb)
    {
       analogWrite(led[0], 255 - rgb.r);
       analogWrite(led[1], 255 - rgb.g);
       analogWrite(led[2], 255 - rgb.b);
    }

  
   String* states;
   int* durations;
   int modeLength;
   int stateNumber;
};
