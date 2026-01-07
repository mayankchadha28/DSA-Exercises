#include <iostream>
#include <vector>
using namespace std;

/* In a Sorted array find the sum of pair
 of numbers such that it gives the target*/

/* Brute force solution - Loop through*/
vector<int> pairSum_bruteforce(vector<int> nums, int target){
    vector <int> ans;
    int n= nums.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(nums[i] + nums[j] == target){
                ans.push_back(i);
                ans.push_back(j);

                return ans;
            }
        }
    }

    return ans;
}

vector<int> pairSum(vector<int> nums, int target){
    vector<int> ans;
    int n= nums.size();

    for(int i=0; i< n; i++){
        
    }
}

int main(){

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    int n= nums.size();

    vector<int> ans = pairSum_bruteforce(nums, target);

    cout << ans[0] << ", " << ans[1] << endl;

    return 0;
}