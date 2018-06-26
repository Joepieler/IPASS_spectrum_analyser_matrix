#include "MSGEQ7.HPP"
#include "hwlib.hpp"

const unsigned int SAMPELS = 16;
const unsigned int OFFSET = 37;

using namespace std;
MSGEQ7::MSGEQ7(hwlib::pin_out & strobe_pin, hwlib::pin_out & reset_pin, hwlib::target::pin_adc & analog_pin):
strobe_pin( strobe_pin ),
reset_pin( reset_pin ),
analog_pin( analog_pin )
{
    reset_pin.set(1);
    hwlib::wait_ms(1);
    reset_pin.set(0);
    hwlib::wait_ms(1);
}




std::array<int, ARRAY_SIZE_MSGEQ7> MSGEQ7::get_data(){    
    
    std::array<int, ARRAY_SIZE_MSGEQ7> data ={};
    reset_pin.set(1);
    hwlib::wait_us(200);
    reset_pin.set(0);
    hwlib::wait_us(200);
    for (unsigned int i = 0; i < ARRAY_SIZE_MSGEQ7; i++){
        strobe_pin.set(1);
        hwlib::wait_us(72);
        strobe_pin.set(0);
        hwlib::wait_us(36);
        
        int average_value = 0; //reset avergae
        for (unsigned int j = 0; j < SAMPELS; j++){
            int spectrum_value = analog_pin.get();
            spectrum_value = spectrum_value - OFFSET;
            if (spectrum_value < 0){
                spectrum_value = 0;
            }
            average_value = average_value + spectrum_value;
        }
        data[i] = average_value / SAMPELS;
    }
    return data;
}