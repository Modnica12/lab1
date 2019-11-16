class Button
{
public:
    Button(int _pin)
    {
        pin = _pin;
        pinMode(pin, INPUT);
        pressed = false;
    }
    bool wasPressed()
    {
        if(!digitalRead(pin) == HIGH && pressed == 0)
        {
            Serial.println("true ");
            pressed = true;
            return true;
        }

        if(!digitalRead(pin) == LOW && pressed == 1)
        {
            pressed = false;
 
            Serial.println("False ");
            return false;
        }
    }
    int pin;
    boolean pressed;    
};
    
