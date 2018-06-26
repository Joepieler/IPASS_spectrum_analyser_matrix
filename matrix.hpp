#ifndef MATRIX_HHP
#define MATRIX_HHP
#include "shiftregister.hpp"
#include "matrix.hpp"
#include "hwlib.hpp"
#include <array>

///@file

/// \brief
/// 2D matrix die gecomineerd is met 2 shiftregisters 
/// \details
/// The size of the matrix is decleard in the ARRAY_SIZE_X AND ARRAY_SIZE_Y.
/// The x_axis, y_axis and matrix_array components are private attributes. 
/// The appropraite constructors and functions are provided.




class matrix{
private:

    ///\brief 
    ///Private
    ///\details
    ///The shiftregisters are for the 2 axis on the 2D matrix. 
    shiftregister x_axis;
    shiftregister y_axis;
    std::array<std::array<bool, ARRAY_SIZE_Y>, ARRAY_SIZE_X> matrix_array;
public:

    ///\brief
    ///constuctor
    ///\details
    ///When the constructor gets initialize its creates a 2D array.
    ///It calls the function clear to fill the array with zeros.
    ///The size of the 2D array is decided by const int ARRAY_SIZE_X and const int ARRAY_SIZE_Y.
    ///The two shiftregisters are added to the object.
    matrix( shiftregister &x_axis, shiftregister &y_axis );
    
    ///\brief
    ///fills de 2D array with false.
    ///\details
    ///When this funcion gets initialize the 2D array gets filled with zeros.
    void clear();
    
    ///\brief
    ///fills de 2D array with True.
    ///\details
    ///When this funcion gets initialize the 2D array gets filled with ones.
    void fill();
    
    ///\brief
    ///changes 1 value in 2D array.
    ///\details
    ///When this function gets initialize it will change 1 specific value.
    ///It will require the coordinate and a boolean.
    ///The boolean will be used to set the value.
    void set( const int & x, const int & y, const bool & value );
    
    ///\brief
    ///returns value element 
    ///\details
    ///When this function gets initialize it will return a specific value.
    ///It will require the coordinate of a element.
    bool get( const int & x, const int & y );
    
    ///\brief
    ///draw to shiftregister
    ///\details
    ///writes the 2D array to the shiftregisters.
    void draw();
};

#endif //MATRIX_HHP