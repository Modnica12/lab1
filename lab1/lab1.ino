#include <Arduino.h>
#include "button.h"
#include "garland.h"
#include "state.h"

#define CHANGE_MODE_BUTTON 13
    
    Button changeModeButton(CHANGE_MODE_BUTTON);
    
    Garland garland;
    
    unsigned long previousMillis = 0;

    int modeNum = 0;
    String states1[] = {YRO, YR_, Y__, OFF, __O, _RO};
    int durations1[] = {500, 500, 500, 500, 500, 500};
    int modeLength1 = 6;

    String states2[] = {R__, _W_, __B};
    int durations2[] = {50, 50, 50};
    int modeLength2 = 3;

    String states3[] = {O__, __P, _W_};
    int durations3[] = {200, 200, 200};
    int modeLength3 = 3;

    // закидываем состоянияб длительность и кол-во состояний для каждого мода
    String* states[] = {states1, states2, states3};
    int* durations[] = {durations1, durations2, durations3};
    int lengths[] = {modeLength1, modeLength2, modeLength3};

    //кол-во модов
    int modes_count = 3;


void setup()
{
    Serial.begin(115200);
    Serial.println("Started!");
    pinMode(first_R_OUT, OUTPUT);
    pinMode(first_G_OUT, OUTPUT);
    pinMode(first_B_OUT, OUTPUT);

    pinMode(second_R_OUT, OUTPUT);
    pinMode(second_G_OUT, OUTPUT);
    pinMode(second_B_OUT, OUTPUT);

    pinMode(third_R_OUT, OUTPUT);
    pinMode(third_G_OUT, OUTPUT);
    pinMode(third_B_OUT, OUTPUT);

    garland.set_mode(states1, durations1, modeLength1);
}

void loop() 
{   
    if (millis() - previousMillis >= garland.get_current_duration())
    {
        garland.set_next_state();
        Serial.println(String(garland.get_current_duration()));
        previousMillis = millis();
    }

    if(changeModeButton.wasPressed())
    {
        //Serial.println("Changed");
        int modeIndex = modeNum % modes_count; // меняем циклически
        garland.set_mode(states[modeIndex], durations[modeIndex], lengths[modeIndex]);
        //Serial.println(String(modeIndex));
        modeNum += 1;
        delay(150);
    }

}
