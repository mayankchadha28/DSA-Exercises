/* 
Leetcode: https://leetcode.com/problems/search-insert-position

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.


Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2

*/


// #include <iostream>
#include <vector>

using namespace std;



/* 
We do binary search 
but we realise when target is not same it is alwways pointing to st

*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int st = 0, end = nums.size()-1;

        while(st <= end){
            int mid = st + (end-st)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid]>target){
                end = mid-1;
            }else{
                st = mid+1;
            }
        }

        return st;
    }

};