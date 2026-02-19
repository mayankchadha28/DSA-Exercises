/* 
Leetcode https://leetcode.com/problems/next-greater-element-i

*/


#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;
/* 
1. right element
2. greater than current
3. immediate

we use reverse approach. right side there is no element so its already -1

most immediate so we use stack (FIFO) to track

basically we store value in the stack compare it with the top
if not higher then we pop it

second step:
unordered map to store for each data and return
*/

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    
        unordered_map<int, int> m;
        stack<int> s;

        for(int i = nums2.size()-1; i>=0; i--){
            while(s.size() > 0 && s.top() <= nums2[i]){
                s.pop();
            }

            if(s.empty()){
                m[nums2[i]] = -1;
            }else{
                m[nums2[i]] = s.top();
            }

            s.push(nums2[i]);
        }

        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            ans.push_back(m[nums1[i]]);
        }

        return ans;
    
    }