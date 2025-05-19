#ifndef Binner_converter_h
#define Binner_converter_h

#include "dynamic_stack.h"
#include <cmath>

std::string convert_binner(int decimal){
    stack binner;
    double number = decimal;
    binner.create();
    while (number > 0){
        number = number/2;
        if(number != floor(number)){
            binner.push('1');
        }else{
            binner.push('0');
        }
        number = floor(number);
    }
    std::string result = "";
    while( binner.top != NULL){
        result = result + binner.top->info;
        binner.pop();
    }
    return result;
}

void convert_decimal(std::string binner);

#endif