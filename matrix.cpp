#include "matrix.hpp"
#include "shiftregister.hpp"
#include "hwlib.hpp"

using namespace std;

matrix::matrix( shiftregister &x_axis, shiftregister &y_axis ):
x_axis( x_axis ), y_axis( y_axis )
{ 
    clear(); 
}

void matrix::draw() {
    std::array<bool, ARRAY_SIZE_X> xarray = {0,0,0,0,0,0,1};
    x_axis.shift_array_x(xarray);
    for (unsigned int x = 0; x < ARRAY_SIZE_X; x++){
            y_axis.shift_array_y(matrix_array[x]);
            hwlib::wait_ms(1);
            x_axis.clock();
    }
}

void matrix::set( const int & x, const int & y, const bool & value ) {
    matrix_array[x][y] = value;
}

void matrix::clear(){
    for (unsigned int x = 0; x < ARRAY_SIZE_X; x++){
        for (unsigned int y = 0; y < ARRAY_SIZE_Y; y++){
            matrix_array[x][y] = 0;
        }
    }
}

void matrix::fill(){
    for (unsigned int x = 0; x < ARRAY_SIZE_X; x++){
        for (unsigned int y = 0; y < ARRAY_SIZE_Y; y++){
            matrix_array[x][y] = 1;
        }
    }
}


bool matrix::get( const int & x, const int & y ){
    return matrix_array[x][y];
}