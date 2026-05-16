
/* Smallest subarray size with Given Sum greater or equal to 8 */
#include <iostream>

using namespace std;

int smallestSubarray(int arr[], int size, int target){

    int minWindowSum = INT_MAX;
    int currWindowSum = 0;

    int windowStart = 0;

    for(int i=0; i<size; i++){

        currWindowSum += arr[i];

        while(currWindowSum >= target){

            minWindowSum = min(minWindowSum, i - windowStart + 1);

            currWindowSum -= arr[windowStart];

            windowStart++;



        }


    }

    return minWindowSum;

}

int main(){
    int arr[] = {4, 2, 2, 7, 8, 1, 2, 8, 10};
    int targetSum = 8;
    int minSum = smallestSubarray(arr, 9, targetSum);

    return 0;
}