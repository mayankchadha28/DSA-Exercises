

/* 
Check if the array is sorted or not

Using traditional method, we would loop through each value one by one

But we can also thing of a solution using recursion 

TC - O(n) - Total calls * work in each call
SC - O(n)

*/
#include <iostream>

using namespace std;


bool isSorted(int arr[], int n){

    if(n==0 || n==1){
        return true;
    }

   return arr[n-1] >= arr[n-2] && isSorted(arr, n-1); 

}


int main(){
    int arr[] = {1, 2, 3, 4, 5};

    cout << isSorted(arr, 5) << endl;

    return 0;
}