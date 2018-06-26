#include "hwlib.hpp"
#include <array>

#ifndef MSGEQ7_HPP
#define MSGEQ7_HPP

const unsigned int ARRAY_SIZE_MSGEQ7 = 7;

class MSGEQ7 {
private:
    hwlib::pin_out & strobe_pin;
    hwlib::pin_out & reset_pin;
    hwlib::target::pin_adc & analog_pin;
public:
MSGEQ7(hwlib::pin_out & strobe_pin, hwlib::pin_out & reset_pin, hwlib::target::pin_adc & analog_pin);
std::array<int, ARRAY_SIZE_MSGEQ7> get_data();
};




#endif //MSGEQ7_HPP