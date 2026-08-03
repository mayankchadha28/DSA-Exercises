/* 
Leetcode: https://leetcode.com/problems/first-unique-character-in-a-string/

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"

Output: 0

Explanation:

The character 'l' at index 0 is the first character that does not occur at any other index.

*/


#include <string>
#include <unordered_map>

using namespace std;

/* 
Idea is to store freq on each character

then use the for loop to check from start which character has freq 1

*/


class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;
        

        for(int i=0; i<s.length(); i++){
            freq[s[i]]++;
        }

        for(int i=0; i<s.length(); i++){
            if(freq[s[i]] == 1){
                return i;
            }
        }
        return -1;

    }
};