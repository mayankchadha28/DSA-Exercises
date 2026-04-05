/* 
Leetcode: https://leetcode.com/problems/longest-consecutive-sequence/description/

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.



Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

*/


// #include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/* 
Brute Force:
- For each num, run while loop checking if num+1 exists (linear search)
- TC: O(n³) | SC: O(1)

Sort:
- Sort array, iterate checking consecutive elements (skip duplicates)
- TC: O(nlogn) | SC: O(1)

Best (HashSet):
- Insert all nums into unordered_set
- Only start counting from streak beginners (num-1 not in set)
- Each element visited at most twice → O(n)
- TC: O(n) | SC: O(n)
*/


int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int max_count = 0;

        for(int num:  nums){
            s.insert(num);
        }

        for(int num: s){ 
            //this single if line can save from tle as it only enters while loop if its first elemeent of seq
            if (!s.count(num - 1)){ 
                int curr_count = 0;
                int curr_elem = num;      
                while(s.find(curr_elem) != s.end()){
                    curr_count++;
                    curr_elem++;
                }   

                max_count = max(max_count, curr_count);
            }
        }

        return max_count;

    }