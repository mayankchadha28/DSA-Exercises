/* 
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
*/


#include <iostream>
#include <vector>

using namespace std;


/*

The idea is check each element of arrays and store in a new array
check remaining elements and add them to array

Time Complexity - O(m+n) + O(m+n)
Space - O(m+n)
*/ 

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
    vector<int>ans(nums1.size(), 0);

        int i =0, j=0, k=0;
        while(i<m && j<n){
            if(nums1[i] < nums2[j]){
            ans[k] = nums1[i];
            i++;
            k++;
        }else{
            ans[k] = nums2[j];
            j++;
            k++;
            }
        }

        while(i < m){
            ans[k++] = nums1[i];
            i++;
        }

        while(j< n){
            ans[k++] = nums2[j++];
        }

        for(int i=0; i< nums1.size(); i++){
            nums1[i] = ans[i];
        }

    }

    /* 
    
     Merge nums2 into nums1 in-place, without extra space.
     nums1 has size m+n: first m elements are real, last n are empty placeholders.
     Since both arrays are sorted, we fill nums1 from the BACK to the FRONT,
     always placing the larger of the two "current largest" candidates
     into the last unfilled slot. This avoids overwriting nums1 values
     before we've read them.
    
     */

    void merge_optimized(vector<int>& nums1, int m, vector<int>& nums2, int n){

        int i=m-1;
        int j = n-1;
        int idx = m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i] >= nums2[j]){
               nums1[idx] = nums1[i];
               i--; 
               idx--;
            }else{
                nums1[idx] = nums2[j];
                j--;
                idx--;
            }
        }

        while(j>=0){
            nums1[idx] = nums2[j];
            j--;
            idx--;
        }

    }