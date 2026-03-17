

/* 
The idea is 

n & n-1 has same bits as n except the rightmost set bit
n has only one set bit and n-1 will have all set bits after that position

n & n-1 will always be 0 if its a power of 2

if n is 0 then retrun 0 by &&
*/

bool ispowerof2(int n){
    return (n && !(n & n-1));
}

