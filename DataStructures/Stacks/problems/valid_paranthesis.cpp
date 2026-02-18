/* 
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

*/


#include <iostream>

using namespace std;


/* 
The idea is to use a stack
insert if its. (, {, [
if not check with closing brackets. 
the last opening bracket should be equal to first closing
if same then pop
else return false 

*/

bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        for(int i=0; i< n; i++){
            if((s[i] == '(') || (s[i] == '[') || (s[i] == '{')){ //open
                st.push(s[i]);
            }else{ //closing
                // match with stack
                if(st.size() == 0){
                    return false;
                }
                if((st.top() =='(' && s[i] == ')') ||
                (st.top() =='{' && s[i] == '}') ||
                (st.top() =='[' && s[i] == ']')
                ){
                    st.pop();
                }else{
                    return false;
                }
            }
        }

        return st.size() == 0;

    }

int main(){
    return 0;
}
