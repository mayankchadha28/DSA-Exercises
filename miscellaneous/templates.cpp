#include <iostream>

using namespace std;

/* 
Templates get created at runtime so errors in the code can not be traced as the function is only generated when called
Eg: change a to some variable. It wont be identified 
*/

template <typename T>
void Print(T a){
    cout << a << endl;
}


int main(){

    Print<int>(10);
    Print<string>("Hello World");

    return 0;
}