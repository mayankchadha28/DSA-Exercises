/* 

*/

#include<iostream>
#include <vector>
#include <set>

using namespace std;



/* 

Loop through each triplet and check if a+b+c == 0
since we need unique we store them in a vector and sort
then we store them in a set. this allows the valueto be uniquely stored and takes care of hash

Time Complexity - O(n3 * log(unique triplets))
Space Complexity - O(unique triplets * 2(constant so can be ignored))

*/
vector<vector<int>> threeSum_bruteforce(vector<int>& nums) {
    
        int n = nums.size();
        vector<vector<int>> ans;

        set<vector<int>> s;

        for(int i=0; i<n; i++){
            int a = nums[i];
            for(int j=i+1; j<n; j++){
                int b = nums[j];
                for(int k=j+1; k<n; k++){
                    int c = nums[k];
                    if(a+b+c == 0){
                       vector<int> trip = {a, b, c};
                       sort(trip.begin(), trip.end());

                       if(s.find(trip) == s.end()){
                        s.insert(trip);
                        ans.push_back(trip);
                       } 
                    }
                }
            }
        }

        return ans;
    }


/* 
we know that a+b+c =0 (target)
b + c = -a (target)
we loop through a and set the value of a
then c = target - b

we find in the set if its unique or exists in the set if it does then we save it to the array
sort the array and store it in set

we then store the values in vector and return

Time Complexity - O(n^2 * log(unique triplets))
Space Complexity O(unique triplets + n)

*/
vector<vector<int>> threeSum_better(vector<int>& nums) {
    
        int n = nums.size();
        
        set<vector<int>> uniqueTriplets;

        for(int i=0; i<n; i++){
            int tar = -nums[i];
            set<int> s;

            for(int j=i+1; j<n; j++){
                int third = tar - nums[j];

                if(s.find(third) != s.end()){
                    vector<int> trip = {nums[i], nums[j], third};
                    sort(trip.begin(), trip.end());

                    uniqueTriplets.insert(trip);
                }

                s.insert(nums[j]);
                
            }
        }

        vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());
        return ans;
    }

/* 
Highly Optimized using 2pointer approach

index i is incremented one at a time
index j is i+1 and k is n-1 (last element)
j, k are treated as 2 pointers
we check if their sum is < 0 then we move forward j++
if sum greater then k--;

else we have our ans when its equal. then we push data to array and then increment pointers
pointers are incremented to ensure the same value is not added.
    
Time complexity - sort(nlogn) + n2 (loops)
O(nlogn + n2)

Space Complexity - O(uniqueTriplets)
*/

vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            int j=i+1, k=n-1;

            if(i>0 && (nums[i] == nums[i-1])) continue; //not to repeat the same i

            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                    j++;
                }else if(sum>0){
                    k--;
                }else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;

                    while(j < k && nums[j] == nums[j-1]){ //not to repeat the same j
                        j++;
                    }
                }
            }
        }

        return ans;



    }
