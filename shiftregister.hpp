#include "hwlib.hpp"
#include <array>
#include "matrix.hpp"
#ifndef SHIFTREGISTER_HPP
#define SHIFTREGISTER_HPP

const unsigned int ARRAY_SIZE_X = 7;
const unsigned int ARRAY_SIZE_Y = 6; 

///@file

///\brief
///shiftregister is based on 74HC595
///\details
///The code uses 2 inputs of the shiftregister.
///The clock pin and the data pin.
 

using namespace std;

class shiftregister{
private:
    hwlib::pin_out & clock_pin;
    hwlib::pin_out & data_pin;
public:

    ///\brief
    ///constuctor
    ///\details
    ///When the constructor gets initialize its creates a object with the 2 pins the chips needs.
    ///Clock pin and data pin.
    shiftregister(hwlib::pin_out & clock_pin, hwlib::pin_out & data_pin);
    
    ///\brief
    ///clock
    ///\details
    ///When the clock gets initialize it will pulses the clock pin.
    void clock();
    
    ///\brief
    ///clear register
    ///\details
    ///It will turn the data to 0 and will clock 8 times.
    void clear();
        
    ///\brief
    ///shift a array to the shiftregister 
    ///\details
    ///It set the array in the shiftregister.
    ///The size is the ARRAY_SIZE_X.
    void shift_array_x(const std::array<bool, ARRAY_SIZE_X> & a);
    
    ///\brief
    ///shift a array to the shiftregister 
    ///\details
    ///It set the array in the shiftregister.
    ///The size is the ARRAY_SIZE_Y.
    void shift_array_y(const std::array<bool, ARRAY_SIZE_Y> & a);
    
    ///\brief
    ///clock one value
    ///\details
    ///The data line will get the value of the boolean and than clock it in and reverse the data line.
    void one_bit(bool a);
};

#endif //SHIFTREGISTER_HPP