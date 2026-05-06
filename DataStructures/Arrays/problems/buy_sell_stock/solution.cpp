/*
Source - Leetcode
PROBLEM STATEMENT: Best time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

*/


#include <iostream>
#include <vector>

using namespace std;


/* 
Consider each day as selling point; preferably sell if user buy at minimum and sell when the price is high

on day 1 it cannot be sold so minBuy will be day 1 valk
day 2 if we sell it may or may not yeirl profit. it if is then calculate profit

check for minimum if the value can be next minimum

Time Complexity - O(n)

*/

int maxProfit(vector<int>& prices){
    int minBuy = prices[0], maxProfit = 0;

        for(int i=1; i< prices.size(); i++){

            if(prices[i] > minBuy){
                maxProfit = max(maxProfit, prices[i]-minBuy);
            }

            minBuy = min(minBuy, prices[i]);
        }

        return maxProfit;
}



int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    maxProfit(prices);


}