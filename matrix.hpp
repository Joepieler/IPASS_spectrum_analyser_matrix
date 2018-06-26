#ifndef MATRIX_HHP
#define MATRIX_HHP
#include "shiftregister.hpp"
#include "matrix.hpp"
#include "hwlib.hpp"
#include <array>

class matrix{
private:
    shiftregister x_axis;
    shiftregister y_axis;
    std::array<std::array<bool, ARRAY_SIZE_Y>, ARRAY_SIZE_X> matrix_array;
public:
    matrix( shiftregister &x_axis, shiftregister &y_axis );
    void clear();
    void fill();
    void set( const int & x, const int & y, const bool & value );
    void draw();
};

#endif //MATRIX_HHP