#include <iostream>


using namespace std;

/* 

f(n) = n + f(n-1)

f(4) -> f(3) -> f(2) -> f(1)

Time Complexity = O(n) +O(1)
Space Complexity = O(n)

Compared to for loop which has same Time Complexity, Space Complexity for for loop is O(1) but for recursion is O(n) due to call
*/

int sum(int n){
    if(n == 1){
        return 1;
    }
    
    return n + sum(n-1);
}