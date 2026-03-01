/* 
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?


Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
*/


#include <iostream>
#include <vector>

using namespace std;


/* 
idea is use a priority queue as it stores largest element on top
after that remove the k elements and pop intil you reach k and return

*/

int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int> q;
        for(int i=0; i<nums.size(); i++){
            q.push(nums[i]);
        }

        for(int i=0; i<k; i++){
            if(i==k-1) return q.top();
            else q.pop();
        }

        return -1;
        
        // sort(nums.begin(), nums.end());

        // return nums[nums.size()-k];
    }