/* 

Swap two numbers without using a third variable

*/
#include <iostream>

using namespace std;

/* 
a = a^b

b = new a ^ b = (a^b) ^ b = a
a = new a^ new b = (a^b) ^ a

*/

int main(){

    int a = 5;
    int b = 3;

    a = a^b;
    b = a^b;
    a = a^b;

    cout << "a= " << a << " b= " << b << endl;

    return 0;
}
