/* 
Leetcode: https://leetcode.com/problems/koko-eating-bananas/

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

*/






#include <iostream>

using namespace std;


// Koko Eating Bananas - Binary Search on answer
// 1. search space is [1, maxPile] for speed k
// 2. for each k, calculate hours = sum of ceil(p/k) for all piles
// 3. if hours <= h, k works -> search left for minimum k
// 4. if hours > h, k too slow -> search right
// 5. hours can overflow int (10^9 * 10^4 = 10^13) -> use long long
// TC: O(n * log(maxPile))

class Solution {
public:

    int minEatingSpeed_bruteforce(vector<int>& piles, int h){
        int max_pile = *max_element(piles.begin(), piles.end());

        for(int k=1; k< max_pile; k++){
            int hours = 0;
            for(int p: piles){
                if (p % k == 0)
                    hours += p / k;
                else
                    hours += p / k + 1;
            }
            if(hours<= h) return k;
        }

        return max_pile;

    }


    int minEatingSpeed(vector<int>& piles, int h) {
        

        int max_pile = *max_element(piles.begin(), piles.end());
        
        int st = 1, end = max_pile;

        int result = INT_MAX;

        while(st<=end){
            int k_mid = st+(end-st)/2;
            long long int hours = 0;
            for(int p: piles){
                if (p % k_mid == 0)
                    hours += p / k_mid;
                else
                    hours += p / k_mid + 1;
            }
            if(hours <=h){
                result = min(result, k_mid);
                end = k_mid-1;
            }else{
                st = k_mid+1;
            }
            

        }

        return result;

        
        // incorrect as this considers all bananas are being eaten and moned to next pile 
        // as we calculate total first

        
        // int totalBananas = 0;
        // for(int i=0; i<n; i++){
        //     totalBananas += piles[i];
        // }

        // int k_speed = 0;
        
        // if(totalBananas % h !=0){
        //     k_speed = (totalBananas/h) + 1; 
        // }else{
        //     k_speed = totalBananas / h;
        // }

        // return k_speed;
    }
};