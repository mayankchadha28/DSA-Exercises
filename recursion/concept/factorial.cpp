#include <iostream>


using namespace std;
/* 
n! = n-1 * n-2 ...

n! = n*(n-1)!

f(n=4) = 4 * f(n=3)

preparing a problem into smaller problems

the problem stops at base case


*/

int factorial(int n){
    if(n == 0) return 1;

    return n * factorial(n-1);


}

int main(){
    cout << factorial(5) << endl;

    return 0;
}