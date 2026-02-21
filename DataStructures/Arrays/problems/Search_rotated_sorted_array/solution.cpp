#include <iostream>
#include <vector>

using namespace std;

/* 
1. Calculate the mid

2. there has to be one or the other side that is sorted
Check if target is equal to mid. return

3. Now check which side is sorted. Left or Right

4. if left is sorted and target lies between 
A[st] <= target <= A[mid]
   left st, mid-1
    if not 
    right mid+1, end

if Right is sorted
A[st] <= target <= A[end]
right st = mid+1
if not 
left end = mid -1



*/

int search(vector<int>& nums, int target) {
        int st = 0, end = nums.size()-1;
        while(st <= end){
            
            // calc mid
            int mid = st + (end-st)/2;

            // if mid is the answer
            if(target == nums[mid]){
                return mid;
            }else if(nums[st]<= nums[mid]){
                if(nums[st] <= target && target <= nums[mid]){
                    end = mid - 1;
                }else{
                    st = mid + 1;
                }
            }else{
                if(nums[mid] <= target && target <= nums[end]){
                    st = mid+1;
                }else{
                    end = mid -1;
                }

        }
    }
    return -1;
    }

int main(){

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int idx = search(nums, target);
    cout << idx << endl;


    return 0;
}