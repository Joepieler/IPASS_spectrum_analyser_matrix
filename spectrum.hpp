#include "hwlib.hpp"
#include "matrix.hpp"
#include "MSGEQ7.HPP"
#include <array>

#ifndef SPECTRUM_HPP
#define SPECTRUM_HPP

const unsigned int max_analog_value = 4096;

///@file

///\brief
///translate soundchip to matrix 
///\details
///The output from the MSGEQ7 needs to get in the matrix.
///This application will put the array from MSGEQ7 to the matrix.

class spectrum{
private:
    matrix & m;
    MSGEQ7 & sound_chip;
public:

    ///\brief
    ///constuctor
    ///\details
    ///When the constructor gets initialize its creates a object with a matrix and MSGEQ7.
    spectrum(matrix & m, MSGEQ7 & sound_chip);
    
    ///\brief
    ///updates the matrix
    ///\details
    ///It wil read the value's from teh MSGEQ7.
    ///Initialize the log_peak fuction.
    ///changes the values in the matrix.
    void update();
    
    ///\brief
    ///determ the numbers of led
    ///\details
    ///checks the value and return the number of leds.
    int log_peak(int peak);
};

#endif //SPECTRUM_HPP