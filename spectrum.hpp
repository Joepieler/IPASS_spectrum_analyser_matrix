#include "hwlib.hpp"
#include "matrix.hpp"
#include "MSGEQ7.HPP"
#include <array>

#ifndef SPECTRUM_HPP
#define SPECTRUM_HPP

const unsigned int max_analog_value = 4096;

class spectrum{
private:
    matrix & m;
    MSGEQ7 & sound_chip;
public:
    spectrum(matrix & m, MSGEQ7 & sound_chip);
    void update();
    int log_peak(int peak);
};

#endif //SPECTRUM_HPP