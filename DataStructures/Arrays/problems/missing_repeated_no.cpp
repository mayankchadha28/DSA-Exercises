/* 
Leetcode: https://leetcode.com/problems/find-missing-and-repeated-values/

You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.

Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

 

Example 1:

Input: grid = [[1,3],[2,2]]
Output: [2,4]
Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].

*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/* 
Repeated - To find repeated we consider using a set which stores unique values. 
We find the value in the set and if we find then we return value a;
If not insert into set.

Missing
Given [1, n^2] so we know total nums can exist are n(n+1)/2 - expected
actual = expected + a - b
we know a, expected and actual(from sum of all)

we calculate b



*/

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> s;
        int n= grid.size();
        int a, b;

        int expSum= 0, actualSum = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){

                actualSum += grid[i][j];

                if(s.find(grid[i][j]) != s.end()){
                    a = grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }

        expSum = (n*n) * (n*n + 1) / 2;

        b = expSum + a - actualSum;
        ans.push_back(b);

        return ans;

    }


    // alternate

    vector<int> findMissingAndRepeatedValues_alternate(vector<vector<int>>& grid) {
        
        unordered_map<int, int> freq_map;
        vector<int> ans(2, 0);
        int n = grid.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<grid[i].size(); j++){
                int curr_val = grid[i][j];
                freq_map[curr_val]++;
            }
        }

        for(int i=1; i<= n * n; i++){
            if(freq_map.find(i) == freq_map.end()){
                ans[1] = i;
            }else if(freq_map[i] > 1) {
                ans[0] = i;
            }
        }

        return ans;
    }