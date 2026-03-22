/* 
C progrma to monitor bit 5 of val1
 if it is high, change value of val2 to 0x55

or change val2 to 0xAA

*/

#include <stdio.h>

#include <stdint.h>


int main(){


    uint8_t val = 0x32;
    uint8_t val2;

    uint8_t getBit = val & 0x20;
    if(getBit){
        val2 = 0x55;
    }else{
        val2 = 0xAA;
    }


    return 0;
}