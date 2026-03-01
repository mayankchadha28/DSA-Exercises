#include <iostream>





/* 
Update Bit

update the position of bit with 0 or 1

idea is to clear bit and then set bit

more flexible as user can decide

*/
int updateBit(int n, int pos, int value){
    int mask = ~(1<<pos);
    n = n & mask;

    return n | value<<pos;

}


/* 
Clear Bit

idea is to shoft bit and have a ones comliment of the number provided and then then 
n =0101
i=2
1<< i = 0100
~0100 = 1011 (ones compliment)

0101 & 1011 = 0001


*/
int clearBit(int n, int pos){
    int mask = ~(1<<pos);
    return (n & mask);
}

/* 
Set Bit

use | as even if pos has 0 it will set to 1 and if 1 then still 1
*/
int setBit(int n, int pos){
    return (n | (1<<pos));
}


/* 
use left shift and check with & 
if the value has 0 then it will return 0 if it has 1 then 1
*/
int getBit(int n, int pos){
    return (n & (1<<pos)!=0);
}


int main(){


    return 0;
}