/*
Source - Leetcode
PROBLEM STATEMENT: Majority Element

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.

// Link: https://leetcode.com/problems/single-number/description/

*/


#include <iostream>
#include <vector>

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
Boyer-Moore Voting Algorithm — O(n) time, O(1) space

Problem: find the element that appears more than n/2 times (the "majority
element"), if one exists.

Core idea: think of it like a tug-of-war/cancellation game.
- Pair up a "vote" for the current candidate with a "vote" against it
  (i.e., an occurrence of some other number). Each such pair cancels out.
- Because the majority element occurs more than n/2 times, it has more
  votes than everything else combined — so no matter how the cancellations
  happen, it can never be fully cancelled out. It always survives as the
  last candidate standing.

Phase 1: find a CANDIDATE (not guaranteed to be the actual majority yet)
Phase 2: verify the candidate actually occurs > n/2 times
*/

int majority_element(vector<int> nums){
    int freq = 0, ans = 0;

    // ---- Phase 1: find a candidate ----
    for(int i = 0; i < nums.size(); i++){
        // freq == 0 means our current candidate has been fully "cancelled
        // out" by other elements so far — pick a fresh candidate: nums[i]
        if(freq == 0){
            ans = nums[i];
        }

        // nums[i] agrees with our candidate -> add a vote
        // nums[i] disagrees -> cancel one vote against it
        if(ans == nums[i]){
            freq++;
        }else{
            freq--;
        }
    }
    // At this point, `ans` is only a CANDIDATE. If a true majority element
    // exists, this loop is guaranteed to find it. But if no element
    // actually has count > n/2, `ans` could be some random wrong value —
    // that's why we verify below.

    // ---- Phase 2: verify the candidate really is the majority ----
    // (skip this phase if the problem guarantees a majority element exists)
    int count = 0;
    for(int val : nums){
        if(val == ans){
            count++;
        }
    }

    if (count > nums.size() / 2)
        return ans;   // confirmed majority element
    else
        return -1;    // no majority element exists
}

int main(){
    vector<int> nums = {2,2, 1,1, 1, 2, 2};

    // majorityElement_bruteforce(nums);



}
