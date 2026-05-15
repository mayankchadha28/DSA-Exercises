/* 
Leetcode: https://leetcode.com/problems/first-unique-character-in-a-string/

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:

Input: s = "leetcode"

Output: 0

Explanation:

The character 'l' at index 0 is the first character that does not occur at any other index.

*/

#include <queue>

using namespace std;


/* 
Using Queue

we store each unique value in a queue

use a map to maintain the counter

remove elements from the start of queue, check if the freq of the char from string is > 1

*/

int firstUniqChar_queue(string s) {
        
        unordered_map<char, int> freq_map;
        queue<int> q;

        for(int i=0; i< s.length(); i++){

            if(freq_map.find(s[i]) == freq_map.end()){
                q.push(i);
            }

            freq_map[s[i]]++;

            while(q.size() > 0 && freq_map[s[q.front()]] > 1){
                q.pop();
            }

        }

       return -1;
    }


/* 
non queue version


Time Complexity - O(2N) -> O(N)
*/

int firstUniqChar(string s){
    unordered_map<char, int> freq_map;

    for(int i=0; i< s.length(); i++){
        freq_map[s[i]]++;
    }
        
    for(int i=0; i<s.length(); i++){
        if(freq_map[s[i]] == 1){
            return i;
       } 
    }

    return -1;
}