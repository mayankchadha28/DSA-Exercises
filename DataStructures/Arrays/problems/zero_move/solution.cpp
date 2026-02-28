#include <iostream>
#include <vector>

using namespace std;


/* 

Time Complexity -O(n)
    Space Complexity O(n)
*/

void moveZeroes_brute(vector<int>& nums) {
        int st= 0;
        int end = st+1;

        vector<int> temp;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                temp.push_back(nums[i]);
            }
        }

        while(temp.size() < nums.size()){
            temp.push_back(0);
        }

        for(int i=0; i<nums.size(); i++){
            nums[i] = temp[i];
        }
    }

    /* 
    Optimized

    The idea is to maintain 2 pointers and push all elements to front
    once we have elements we can loop through all elements and push 0 at end

    Time Complexity -O(n)
    Space Complexity O(1)
    
    */

    void moveZeroes(vector<int>& nums) {
        int writer = 0;
        for(int reader=0; reader< nums.size(); reader++){
            if(nums[reader] != 0){
                nums[writer] = nums[reader];
                writer++;
            }
        }   

        while(writer< nums.size()){
            nums[writer] =0;
            writer++;
        }
    }