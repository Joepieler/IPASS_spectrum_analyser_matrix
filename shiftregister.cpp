#include "shiftregister.hpp"
#include "hwlib.hpp"

using namespace std;

shiftregister::shiftregister(hwlib::pin_out & clock_pin, hwlib::pin_out & data_pin):
    clock_pin( clock_pin ),
    data_pin( data_pin )
{
    clear();
}

void shiftregister::clock(){
    clock_pin.set(1);
    clock_pin.set(0);
}

void shiftregister::clear(){
    data_pin.set(0);
    for (unsigned int i = 0; i <= ARRAY_SIZE_Y; i++){
        clock();
    }
}

void shiftregister::set( bool value ) {
    data_pin.set( value );
}

void shiftregister::shift_array_y(const std::array<bool, ARRAY_SIZE_Y> & a){
    for (unsigned int i = 0; i <= ARRAY_SIZE_Y; i++){
        if (a[i]==1){
            data_pin.set(0);
        }else{
            data_pin.set(1);
        }
        clock();
    } 
}

void shiftregister::shift_array_x(const std::array<bool, ARRAY_SIZE_X> & a){
    for (unsigned int i = 0; i <= ARRAY_SIZE_X; i++){
        if (a[i]==1){
            data_pin.set(1);
        }else{
            data_pin.set(0);
        }
        clock();
        data_pin.set(0);
    } 
}

void shiftregister::one_bit(bool a){
    data_pin.set(a);
    clock();
    if (a == 1){
        data_pin.set(0);
    }else{
        data_pin.set(1);
    }
}