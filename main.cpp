#include "hwlib.hpp"
#include <array>
#include "shiftregister.hpp"
#include "matrix.hpp"
#include "MSGEQ7.HPP"
#include "spectrum.hpp"

//const unsigned int ARRAY_SIZE_X = 7;
//const unsigned int ARRAY_SIZE_Y = 6; 

    namespace target = hwlib::target;

int main( void ){	
    
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   auto reset_pin = hwlib:: target::pin_out(hwlib::target::pins::d8);
   auto strobe_pin = hwlib:: target::pin_out(hwlib::target::pins::d9);
   auto analog_pin = hwlib::target::ad_pins::a1;
   auto analog = hwlib::target::pin_adc(analog_pin);
   auto data_x = target::pin_out( target::pins::d1 );
   auto clock_x = target::pin_out( target::pins::d2 );
   auto data_y = target::pin_out( target::pins::d4);
   auto clock_y = target::pin_out( target::pins::d5);
   
   MSGEQ7 chip(strobe_pin,reset_pin,analog);
   shiftregister xshift(clock_x,data_x);
   shiftregister yshift(clock_y, data_y);
   
   
   matrix matrixled( xshift, yshift );
   spectrum matrix_chip(matrixled, chip);
    int counter = 0;
   for(;;) {
       matrixled.draw();
       if (counter == 20){
           counter = 0;
            matrixled.clear();
            matrix_chip.update();
            
       }
       counter++;
   }
}
