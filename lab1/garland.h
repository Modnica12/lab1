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


int off[] = {0, 0, 0};  


// colors
int colorRed[] = {255, 0, 0};
int colorGreen[] = {0, 255, 0};
int colorBlue[] = {0, 0, 255};
int colorWhite[] = {255, 255, 255};
int colorPurple[] = {170, 0, 255};
int colorYellow[] = {255, 210, 0};
int colorOrange[] = {240, 69, 0};


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
          set_rgb_led(currentLed, off);
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
      
    void set_rgb_led(int led[], int rgb[])
    {
       analogWrite(led[0], 255 - rgb[0]);
       analogWrite(led[1], 255 - rgb[1]);
       analogWrite(led[2], 255 - rgb[2]);
    }

  
   String* states;
   int* durations;
   int modeLength;
   int stateNumber;
};
