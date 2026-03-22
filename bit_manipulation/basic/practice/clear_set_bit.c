#include <stdio.h>

/* 
set bit and then clear bit only bit 4(5th bit) repeatedly without disturbing rest of the bits

*/

int main(){

    unsigned char val;

    while(1){
        val = (val | 0x10) ;//set

        val = (val & 0xEF); //clear

        // or  

        val = val ^ 0x10;
    }

    return 0;
}