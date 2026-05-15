#include <iostream>

using namespace std;


/* 
Add values until it reaches K window
then we can remove the first number and add the next number

*/

int maxSubarraySum(int arr[], int size, int k){
    int maxSum = INT_MIN;
    int currSum = 0;

    for(int i=0; i< size; i++){
        currSum += arr[i];

        if(i >= (k-1)){
            maxSum = max(currSum, maxSum);

            currSum -= arr[i - (k-1)];

        }
    }

    return maxSum;

}


int main(){
    int arr[] = {4, 2, 1, 7, 8, 1, 2, 8, 1, 0};
    int maxSum = maxSubarraySum(arr,10, 3);
    return 0;
}