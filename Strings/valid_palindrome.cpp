#include <iostream>
#include <string>
#include <cctype>

using namespace std;



/* 

Using 2 pointer approach

st=0; end = size-1
Loop 

check if the first index is alpha numeric if not then increment the start index and continue

check if the end index is alpha numeric if not then increment the end index and continue

convert all the values to lowercase so its easy to compare

compare the value if they're not same then return false

increment the start and end index

if nothing fits then it is a valid palindrome




*/

// Write your own function or there is a built in cpp method isalnum(ch)
bool isAlphaNum(char ch){
        if((tolower(ch) >= 'a' && tolower(ch) <= 'z') ||
            (ch >= '0' && ch <= '9')){
            return true;
        }

        return false;

        // return isalnum(ch);

    }

    bool isPalindrome(string s) {
        int st=0, end = s.length()-1;

        while(st < end){

            if(!isAlphaNum(s[st])){
                st++; continue;
            }

            if(!isAlphaNum(s[end])){
                end--; continue;
            }

            if(tolower(s[st]) != tolower(s[end])){
                return false;
            }

            st++; 
            end--;
        }

        return true;

    }

int main(){




    return 0;
}
