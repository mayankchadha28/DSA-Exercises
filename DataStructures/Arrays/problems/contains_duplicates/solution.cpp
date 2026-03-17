/* 
Leetcode: https://leetcode.com/problems/contains-duplicate/

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 
Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.


*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/* 
Solution 1 - Maintain 2 for loops and check individually
Time Complexity - O(n2)
*/

/* 
Solution 2 - Sort the array and then loop. compare it with the next value

Time complexity - O(nlog n) + O(n) = O(nlogn)

*/


/*
Maintain an unordered set. this only stores unique values.
check if value already exist then return if not insert
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;

        for(int num: nums){
            if(seen.find(num) != seen.end()) return true;
            seen.insert(num);
        }
        return false;
    }
};