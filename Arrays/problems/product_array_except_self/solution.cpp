#include <iostream>
#include <vector>

using namespace std;

/*Bruce Force

Loop through array

Add another loop where you multiple all values and exclude when i==j i.e the same index

return answer

Time Complexity - O(n2)
*/

vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size, 1);
        // int currVal = 1;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i != j) {
                    ans[i] *= nums[j];
                }
            }
        }
        return ans;
    }


/*
From any index i; Calculate the left product (prefix) of numbers and Right product (suffix) of number
(prefix) left product - i (index) - (suffix) right product


1 - calculate product prefix for all numbers

2 - suffix for all numbers


Time Complexity - O(3n) = O(n)

Note: This optimizes the time but not the space yet
*/

vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        for(int i=n-2; i>=0; i--){
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        for(int i=0; i<n; i++){
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;

        
    }


/*
Optimized for Space Complexity

instead of storing variables seperately in prefix and suffix vector and later multiply

why not multiply with the answer directly?

*/

vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        

        for(int i=1; i<n; i++){
            ans[i] = ans[i-1] * nums[i-1];
        }

        int suffix = 1;
        for(int i=n-2; i>=0; i--){
            suffix *= nums[i+1];
            ans[i] *= suffix;
        }

        return ans;
    }