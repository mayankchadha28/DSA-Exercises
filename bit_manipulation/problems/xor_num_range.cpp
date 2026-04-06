/* 
XOR of Numbers & XOR of numbers in range

*/


// XOR from 1 to N pattern (repeats every 4):
// N%4==1 → N1 |  N%4==2 → N+1  |  N%4==3 → 0  |  N%4==0 → N
//
// N=1: 1        (1%4=1 → 1)
// N=2: 1^2=3    (2%4=2 → 3)   ← result is 1, not N
// N=3: 3^3=0    (3%4=3 → 0)
// N=4: 0^4=4    (4%4=0 → N)
// N=5: 4^5=1    (5%4=1 → 1)
// N=6: 1^6=7    (6%4=2 → 7)   



int sequence(int N){

    if(N % 4 == 1 ) return 1;
    else if(N % 4 == 2) return N+1;
    else if(N % 4 == 3) return 0;
    else return N; 

}


/* 
Find XOR of Numbers from 1 to R
Find the XOR of NUmbers from 1 to L

XOR of these 2

Eg: 4-7
(1^2^3)^(1^2^3^4^5^6^7)
as 2^2 = 0 numbers cancel out

*/

int sequece_range(int left, int right){

    return sequence(left-1)^sequence(right);

}


int main(){

}