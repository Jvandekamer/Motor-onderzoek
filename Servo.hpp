#ifndef SERVO_HPP
#define SERVO_HPP

#include "hwlib.hpp"
#include "PCA9685.hpp"

class Servo{
private:
    PCA9685_i2c & Pca;
    const uint8_t PinNumber;
    int16_t MinValue,MaxValue,MinTime,MaxTime;
    

    int16_t map(int16_t Value);

public:
    Servo(PCA9685_i2c & Pca, uint8_t PinNumber, int16_t MinTime, int16_t MaxTime, int16_t MinValue, int16_t MaxValue, bool IsInverted = false):
        Pca(Pca),
        PinNumber(PinNumber),
        MinValue(MinValue),
        MaxValue(MaxValue),
        MinTime(MinTime),
        MaxTime(MaxTime)
    {
        if(IsInverted){
            ToggleInvert();
        }
    }
    
    void ToggleInvert();

    void SetPosition(int16_t Value);
    
    void SetPosition(int NumberOfMicroSeconds);

};
#endif // SERVO_HPP