/* 
Leetcode: https://leetcode.com/problems/single-number-ii/

Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:

Input: nums = [2,2,3,2]
Output: 3

TC - O(nlogn)+ n/3
SC - O(1)

*/

#include <iostream>

using namespace std;



/* 
Bit manipulation - Approach 3 (Best)

consider 3 buckets 3 variables
first bucket stores values which were 1
second which were 2
third which were 3 (not needed as we are only interested in 1 and more than 1)

num[i] will go to 1, if not in 2s 
num[i] will go to 2s, if it is in 1s (add in 2s, delete in 1s)
num[i] will go to 3s, if it is in 2s




*/
int singleNumber(vector<int>& nums) {
        
        int ones = 0, twos = 0;
        for(int i=0; i< nums.size(); i++){
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }

        return ones;

    }


/* 
Bit manipulation - Approach 2

The idea is to sort the array first
[1,1,1,2, 3,3,3]
start from the first index rather than 0. if the index -1 and index+1 is same then advance to 3
repeat
if its not then return the number

TC = n*32


*/
 int singleNumber_1(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        for(int i=1; i<n; i+=3){
            if(nums[i-1] != nums[i]){
                return nums[i-1];
            }
        }
        return nums[n-1];

    }

/* 

Bit manipulation - Approach 1 (not very optimized)

loop through each bit and count the no of set bits. if each bit is not a multiple ofit set that bit in ans
Eg:
0 1 1 - 3
1 0 1 - 5
0 1 1 - 3
0 1 1 - 3

*/
int singleNumber_2(vector<int>& nums) {
        
        int ans = 0;
        for(int bit_idx=0; bit_idx<32; bit_idx++){
            int count = 0;
            for(int i=0; i<nums.size(); i++){
                if(nums[i] & (1<< bit_idx)){
                    count++;
                }
            }
            if(count%3 == 1){
                ans |= (1<< bit_idx);
            }
        }

        return ans;

    }

/* 

Without Bit manipulation
Use Map to store frequency

TC - O(n);
*/
int singleNumber_4(vector<int>& nums) {
        unordered_map<int, int>m;
        for(int no: nums){
            m[no]++;
        }

        for(auto &p: m){
            if(p.second == 1){
                return p.first;
            }
        }

        return -1;
    }

int main(){

    return 0;
}