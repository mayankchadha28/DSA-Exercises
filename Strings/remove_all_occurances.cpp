/* 
Leetcode: 1910

url: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/


*/

#include <iostream>
#include <string>

using namespace std;



/* 

find the string

erase the string

note: part.length() and not part.length()-1 because len is the count of characters, not an “end index.”

*/


string removeOccurrences(string str, string part) {
        
        while(str.find(part) < str.length()){
            
            str.erase(str.find(part), part.length());
            
        }

        return str;
    }

