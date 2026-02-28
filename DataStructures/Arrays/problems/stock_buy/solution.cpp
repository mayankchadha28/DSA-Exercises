/* 
Leetcode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.


*/


#include <iostream>
#include <vector>

using namespace std;

/* 
The idea is to consider each day as selling point.
we initialize the day 1 to buy by default

if the prices today are greater than our previous buy we can update
if not we can check if the prices are minimum then we can later sell it.

Time Complexity - O(n)

// TODO
Note: This problem can also use Dynamic Programming approach (Later excersises)

*/


int maxProfit(vector<int>& prices) {
        int maxProfit = 0, bestBuy = prices[0];

        for(int i=1; i< prices.size(); i++){
            if(prices[i] > bestBuy){
                maxProfit = max(maxProfit, prices[i]-bestBuy);
            }
            bestBuy = min(bestBuy, prices[i]);

        }
        return maxProfit;
    }