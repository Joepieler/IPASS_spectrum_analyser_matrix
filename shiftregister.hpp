#include "hwlib.hpp"
#include <array>
#ifndef SHIFTREGISTER_HPP
#define SHIFTREGISTER_HPP

const unsigned int ARRAY_SIZE_X = 7;
const unsigned int ARRAY_SIZE_Y = 6; 

using namespace std;

class shiftregister{
private:
    hwlib::pin_out & clock_pin;
    hwlib::pin_out & data_pin;
public:
    shiftregister(hwlib::pin_out & clock_pin, hwlib::pin_out & data_pin);
    void clock();
    void clear();
    void set(bool value);
    void shift_array_x(const std::array<bool, ARRAY_SIZE_X> & a);
    void shift_array_y(const std::array<bool, ARRAY_SIZE_Y> & a);
    void one_bit(bool a);
};

#endif //SHIFTREGISTER_HPP