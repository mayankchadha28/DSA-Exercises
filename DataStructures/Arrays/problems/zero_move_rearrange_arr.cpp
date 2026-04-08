#include <iostream>
#include <vector>


// TODO
using namespace std;

vector<int> shiftNumbers(vector<int> &nums){

    vector<int> ans;

    int pos = 0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] < 0){

        }
    }

} 


int main(){

    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> ans = shiftNumbers(nums);

    for(int i: ans){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}