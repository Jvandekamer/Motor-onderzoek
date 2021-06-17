#include "hwlib.hpp"
#include "PCA9685.hpp"
#include "Servo.hpp"

int main() {
    namespace target = hwlib::target;

    // building pca object
    auto scl = target::pin_oc(target::pins::scl);
    auto sda = target::pin_oc(target::pins::sda);
    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);
    auto PCA = PCA9685_i2c(i2c_bus);

    //  Initialize the PCA9685 with the values for this project
    PCA.begin();
    PCA.setPWMFreq(50);
    hwlib::wait_ms(10);

    //building servo object
    Servo sg90(PCA,2,1000,2000,-127,127);
    
    //required variables
    volatile bool _true = true;
    int16_t stop = 0;
    int16_t drive = 127;

    // start motor
    sg90.SetPosition(drive);
    
    // wait a second
    hwlib::wait_ms(1000);
    
    // stop the motor
    sg90.SetPosition(stop);
    
    while (_true) {

    }
}