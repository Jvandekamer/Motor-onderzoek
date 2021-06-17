#include "Servo.hpp"

int16_t Servo::map(int16_t Value){
    return ((int)((float)(Value - this->MinValue) * (float)(this->MaxTime - this->MinTime) / (float)(this->MaxValue - this->MinValue) + this->MinTime));
}

void Servo::ToggleInvert(){
    int16_t temp = this->MaxValue;
    this->MaxValue = this->MinValue;
    this->MinValue = temp;
}

void Servo::SetPosition(int16_t Value){
    Pca.writeMicroseconds(this->PinNumber,map(Value));
}
