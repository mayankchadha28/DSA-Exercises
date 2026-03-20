

/* 

Leetcode: https://leetcode.com/problems/valid-palindrome-ii

Given a string s, return true if the s can be palindrome after deleting at most one character from it.


Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.


*/


#include <iostream>

using namespace std;


/* 

Idea is to use 2 pointer approach to check values if they are different deligate to a secondary to check if st++ or end-- if we continue its still valid. 

if not return

*/

class Solution {
public:

    bool isPalindrome(string s, int st, int end){
        while(st < end){
            if(s[st] == s[end]){
                st++;
                end--;
            }else return false;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int st = 0;
        int end = s.length()-1;
            
        while(st < end){

            if(s[st] == s[end]){
                st++;
                end--;
            }else{
                return isPalindrome(s, st+1, end) || isPalindrome(s, st, end-1);
            }
        }
        return true;
    }
};