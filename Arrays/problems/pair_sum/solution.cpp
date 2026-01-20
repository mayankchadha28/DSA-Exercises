#include <iostream>
#include <vector>
using namespace std;

/* In a Sorted array find the sum of pair
 of numbers such that it gives the target*/

/* Brute force solution - Loop through
Time Complexity - O(n^2) 
*/
vector<int> pairSum_bruteforce(vector<int> nums, int target){
    vector <int> ans;
    int n= nums.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(nums[i] + nums[j] == target){
                ans.push_back(i);
                ans.push_back(j);

                return ans;
            }
        }
    }

    return ans;
}

/* Maintain 2 indexes i, j 
PS > Target -> decrement j (we want to reduce our sum to the target as much as possible)
PS < Target -> increment i (We want to increase i so it can reach the target)
PS = Target -> Best case return the solution

Time Complexity - O(n) 
*/
vector<int> pairSum(vector<int> nums, int target){
    vector<int> ans;
    int n= nums.size();
    int currSum = 0;
    int st=0, end = n-1;

    while(st<=end){
        currSum = nums[st] + nums[end];
        if(currSum > target){
            end--;
        }else if(currSum < target){
            st++;
        }else {
            ans.push_back(st);
            ans.push_back(end);

            return ans;

        }
    }
    
    return ans;

    
}

int main(){

    vector<int> nums = {2, 7, 11, 15};
    int target = 26;
    // int n= nums.size();

    // vector<int> ans = pairSum_bruteforce(nums, target);
    vector<int> ans = pairSum(nums, target);

    cout << ans[0] << ", " << ans[1] << endl;

    return 0;
}