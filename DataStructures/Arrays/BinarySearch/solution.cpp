/* 
Sample Binary Search Implementation 

*/

#include <iostream>
#include <vector>

using namespace std;


int binarySearch(vector<int> arr, int tar){
    int st=0, end= arr.size()-1;

    while(st <= end){
        int mid = (st+end)/2;

        if(tar > arr[mid]){
            st = mid+1; //2nd half
        }else if(tar < arr[mid]){
            end = mid-1; //1st half
        }else{
            return mid;
        }   
    }

    return -1;
}


/* 

Optimized Code -
st, end can be INT_MAX - this will go beyond what int can store so we use a modified version of the formula

mid = st+ (end-st)/2

This avoids overflow

Note: Apply the updated formula when you have to calculate start and end

*/

int main(){

    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12}; //odd
    int tar1 = 4;

    cout << binarySearch(arr1, tar1) << endl;

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12}; //even
    int tar2 = 0;

    cout << binarySearch(arr2, tar2) << endl;


    return 0;

}
