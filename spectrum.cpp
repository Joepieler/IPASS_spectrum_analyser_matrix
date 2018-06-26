#include "matrix.hpp"
#include "MSGEQ7.hpp"
#include "hwlib.hpp"
#include "spectrum.hpp"
#include <array>

spectrum::spectrum(matrix & m, MSGEQ7 & sound_chip):
    m( m ),
    sound_chip( sound_chip )
    {}
    
    
int spectrum::log_peak(int peak){
    if (peak > 3858){//931
        return 6;
    }else if(peak > 2927){//798
        return 5;
    }else if (peak > 2130){//665
        return 4;
    }else if(peak > 1464){//532
        return 3;
    }else if(peak > 932){//+399
        return 2;
    }else if(peak > 533){//+266
        return 1;
    }else if(peak > 133){// baseline
        return 0;
    }
    return 0;
}



void spectrum::update(){
    std::array<int, ARRAY_SIZE_MSGEQ7> s = sound_chip.get_data();
    for (unsigned int x = 0; x < ARRAY_SIZE_MSGEQ7; x++){
        int number_of_leds = log_peak(s[x]);
        for (int y = 0; y < number_of_leds; y++){
            m.set(x,y,true);
        }
    }
    
}