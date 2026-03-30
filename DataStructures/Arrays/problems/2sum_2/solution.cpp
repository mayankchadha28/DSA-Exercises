/* 
Leetcode 167: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers index1 and index2, each incremented by one, as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

*/
#include <iostream>

using namespace std;


/* 

This is very similar to 2 sum. 
But since the array is sorted we can use 2 sum

if not st = target - end

both approaches shoudl do the job

since we cannot take extra space we prefer 2 sum


*/

vector<int> twoSum(vector<int>& numbers, int target) {

        int st= 0, end = numbers.size()-1;
        vector<int> ans;
        while(st < end){
            int sum = numbers[st] + numbers[end];
            if(sum == target){
                ans.push_back(st+1);
                ans.push_back(end+1);
                return ans;
            }else if(sum > target){
                end--;
            }else{
                st++;
            }
        }
        return {-1, -1};
    }