#include <iostream>

using namespace std;

/* 

5 = 0101
i =2

using left shift
(1<<i) = 0100
result = 100

using right shift
num >> i = 0001
& 1 


*/

bool check_bit(int n, int pos){

    if((n & (1 << pos)) != 0){
        cout << "ith bit is set" << endl;

        return true;
    }

    return false;

}

int set_bit(int n, int pos){
    return n |= (1<<pos);
}

int clear_bit(int n, int pos){
    return (n & ~(1<<pos));
}

int toggle_bit(int n, int pos){
    return (n ^ (1<<pos));
}


/* 
remove last set bit
1 1 0 0
so 1 at pos 2 should be removed

result: 1 0 0 0
*/
int remove_last_set_bit(int n){


}

int main(){

    int n = 5;
    int i = 2;
    
    check_bit(n, i);
    set_bit(n, i);
    clear_bit(n, i);


    return 0;
}