#include "hwlib.hpp"
#include <array>

#ifndef MSGEQ7_HPP
#define MSGEQ7_HPP

///@file

/// \brief
/// MSGEQ7 is a Seven Band Graphic Equalizer
/// \details
/// MSGEQ7 is a Seven Band Graphic Equalizer.
/// The chip spits the audio spectrum in 7 bands.
/// for more information see datasheet https://www.sparkfun.com/datasheets/Components/General/MSGEQ7.pdf


const unsigned int ARRAY_SIZE_MSGEQ7 = 7;

class MSGEQ7 {
private:

    ///\brief
    ///pins
    ///\details
    ///The chip needs 3 input pins and has 1 output pin.
    ///2 input pins are from the arduino.
    ///The other input is the audio in
    ///The output from the chip we use a analogread pin from the arduino.
    hwlib::pin_out & strobe_pin;
    hwlib::pin_out & reset_pin;
    hwlib::target::pin_adc & analog_pin;
public:

    ///\brief
    ///constuctor
    ///\details
    ///When the constructor gets initialize its creates a object with the 3 pins the chips needs.
    ///Strobe pin, reset pin and de analog in pin.
    MSGEQ7(hwlib::pin_out & strobe_pin, hwlib::pin_out & reset_pin, hwlib::target::pin_adc & analog_pin);
    
    ///\brief
    ///gets data chip
    ///\details
    ///The function returns the data of the 7 bands in a array whit the size of 7.
    ///The array is filled with integers betwheen 0 and 4096.
    ///This is what the arduino due returns from a analog port.
    ///In the function is a filter build in, the number of samples is declared in SAMPLES.    
    std::array<int, ARRAY_SIZE_MSGEQ7> get_data();
};




#endif //MSGEQ7_HPP