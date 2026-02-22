/* 

Leetcode: https://leetcode.com/problems/container-with-most-water/

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

*/

#include <iostream>
#include <vector>

using namespace std;


/* 
The idea is to maintain 2 pointers 
st , end

the container can only contain min ht level so we calculate the area
then we move the pointer which is small as the water level will even reduce if we move higher

Time Complexity- O(N)

*/

int maxArea(vector<int>& height) {
        int maxWater = 0;
        int st = 0;
        int end = height.size()-1;

        while(st < end){
            int width = (end-st);
            int ht = min(height[st], height[end]);
            int currWater = width * ht;
            maxWater = max(currWater, maxWater);
            
            height[st] < height[end] ? st++ : end--;
        }


        return maxWater;
    }