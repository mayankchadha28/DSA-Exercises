/* 
Leetcode: https://leetcode.com/problems/valid-anagram/

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

*/

#include <iostream>
#include <vector>

using namespace std;

/* 
Solution 1: sort the arrays and check if they are same or not

Time Complexity - O(nlogn)

not optimized

NOTE: this works fine on vectors/strings 
but if we had to do it for array of char its just a pointer so it wont work.
*/

bool isAnagram(string s, string t) {
        if (s.size() != t.size() )return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }


/* 
    Solution 2: create an array of 26 (a-z) as it contains only lowercase. 
    get the index via a and increment the value in an array
    now we can use the same array but subtract
    if the value is 0 then its an anagram
    else return false

    This is only valid if it does not contain any other char 
    
*/

bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;

        int count[26] = {0};

        for(char ch : s){
            count[ch - 'a']++;
        }

        for(char ch: t){
            count[ch - 'a']--;
        }

        for(int val: count){
            if(val != 0) return false;
        }
        return true;
    }


/* 
Solution 3: this solution supports all type of data

use an unordered map to store all values then subtract the actual value if they value is not 0 then return false

NOTE: iterating over a map will give you value as a pair. you must access via m.first, m.second


*/

bool isAnagram(string s, string t) {

        unordered_map<char, int> m1;

        for(int i=0; i < s.size(); i++){
            m1[s[i]]++;
            m1[t[i]]--;
        }

        for(auto val: m1){
            if(val.second != 0) return false;
        }

        return true;


    }