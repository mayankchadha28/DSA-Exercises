/*
Source - Leetcode
PROBLEM STATEMENT: Majority Element

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.

// Link: https://leetcode.com/problems/single-number/description/

*/


#include <iostream>
// #include <vector>

using namespace std;

/*
Brute Force Solution

Iterate over all array values and get the count of elements
if the count is more than n/2 then return the value

*/
int majorityElement_bruteforce(vector<int>& nums) {
        int n = nums.size();
        
        for(int val: nums){
            int freq = 0;
            for(int el: nums){
                if(val == el){
                    freq++;
                }
            }
            if(freq > n/2){
                return val;
            }
        }
        return -1;
}

/*
Slightly Optimized Solution

First Sort an Array - Time Complexity nlogn
Since the array is sorted if the value is not greater than n/2 we can discard and reset the freq
repeat this until we find the value

Note: By default you can set the freq to 1 as it is the first element

Then time complexity will be O(nlog + n)
which is nlogn Slighly efficient than n^2
*/

int majority_element_optimized(vector<int>& nums){
    int n = nums.size();

    // Sort
    sort(nums.begin(), nums.end());

    // freq count
    int freq= 1, ans = nums[0];
    for(int i=1; i< n; i++){
        if(nums[i] == nums[i-1]){
            freq++;
        }else{
            freq = 1;
            ans = nums[i];
        }

        if(freq > n/2){
            return ans;
        }

    }

    return ans;

}

/*
Time Complexity (n)

This is the highly optimized solution based on Moores voting algorithm
consider if a candidate has lost in 3 cities but if the candidate has won 
in major cities he will still be the highest

set initial frequency as 0

if the frequency is 0 set the answer 

increment(increase the power) if the solution is found and if not decrement(decrease the power)

to stay in the majority of the elements it will anyways be more than half (n/2) 
so freq will always be greater than 0
*/

int majority_element(vector<int> nums){
    int freq =0, ans = 0;

    for(int i=0; i< nums.size(); i++){
        if(freq == 0){
            ans = nums[i];
        }

        if(ans == nums[i]){
            freq++;
        }else{
            freq--;
        }
    }

    // if its not given that the answer will; exist or not
    //  there can be no elements that are matching

    int count = 0;
    for(int val: nums){
        if(val == ans){
            count++;
        }
    }

    if (count > nums.size() / 2)
        return ans;
    else
        return -1;


    return ans;

}

int main(){
    vector<int> nums = {2,2, 1,1, 1, 2, 2};

    // majorityElement_bruteforce(nums);



}
