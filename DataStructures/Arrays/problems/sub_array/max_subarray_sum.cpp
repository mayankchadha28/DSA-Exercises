#include <iostream>
#include <vector>
using namespace std;

//brute force
int main_bruteforce(){
    int n=5;
    int arr[5] = {1, 2, 3, 4, 5};

    int maxSum = INT_MIN;

    for(int st=0; st<n; st++){
        int currSum = 0;
        for(int end=st; end<n; end++){
            currSum += arr[end];
            maxSum = max(currSum, maxSum);    
        }
        
    }

    cout << "max subarray sum = " << maxSum << endl;

    return 0;
}

// Kadane's Algorithm
int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int currSum = 0, maxSum = INT_MIN;

        for(int val: nums){
            currSum += val;
            maxSum = max(currSum, maxSum);

            if(currSum < 0){
                currSum = 0;
            }       
        }
        return maxSum;

}

