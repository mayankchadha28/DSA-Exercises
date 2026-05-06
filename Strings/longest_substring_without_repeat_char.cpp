/* 
Leetcode: https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string s, find the length of the longest substring without duplicate characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

*/


// #include <iostream>
#include <unordered_set>

using namespace std;


/* 
same sliding window but more readable

*/
int lengthOfLongestSubstring(string s){

    unordered_set<char>myset;
        int longestSubstr = 0;
        int left=0, right=0;
        while(right < s.length()){

            if(myset.find(s[right]) == myset.end()){
                myset.insert(s[right]);
                
            }else{
                while(myset.find(s[right]) != myset.end()){
                    myset.erase(s[left]);
                    left++;
                }
                myset.insert(s[right]);
            }
            longestSubstr = max(longestSubstr, right - left + 1);
            right++;
            

        }

        return longestSubstr;



}




/* 
Use a set to store unique characters; 
use a sliding window approach when you reach the repeated character

this version is very raw
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>string_set;

        int longestSubstr = 0;
        int maxLen = 0;
        int l=0;
        for(int i=0; i< s.size(); i++){

            if(string_set.find(s[i]) == string_set.end()){
                string_set.insert(s[i]);
                maxLen++;
            }else{
                
                while(string_set.find(s[i]) != string_set.end()){
                    string_set.erase(s[l]);
                    l++;
                    maxLen--;
                }
                string_set.insert(s[i]);
                maxLen++;
            }

            longestSubstr = max(longestSubstr, maxLen);

        }

        return longestSubstr;

    }
};