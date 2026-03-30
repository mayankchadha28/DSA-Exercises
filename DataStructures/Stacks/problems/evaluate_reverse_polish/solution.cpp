/* 
Leetcode: https://leetcode.com/problems/evaluate-reverse-polish-notation/

You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

*/

#include <iostream>
#include <string>

using namespace std;




/* 
TODO: Try implementing without stack O(n2)
*/



/* 
refactored code
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        
        int ans =0;
        string operators = "+-/*";
        stack<int> st;
        for(string token: tokens){

            if(operators.find(token) == string::npos){
                st.push(stoi(token));
                continue;
            }

            int num2 = st.top();
            st.pop();
            int num1 = st.top();
            st.pop();

            int result = 0;
            if(token == "+"){
                result = num1 + num2;
                st.push(result);
            }else if(token == "-"){
                result = num1 - num2;
                st.push(result);
            }else if(token == "*"){
                result = num1 * num2;
                st.push(result);
            }else if(token == "/"){
                result = num1/num2;
                st.push(result);
            }
        }

        return st.top();
    }
};


/* 
This is not the refactored code for reference

The idea is to use a stack to add the number. once the operator is found
pop 2 values and then do the operation
then store the result in the stack

*/

class Solution_old {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        
        int ans =0;
        stack<int> st;
        for(int i=0; i<n; i++){
            if(tokens[i] == "+" || 
            tokens[i] == "-" ||
            tokens[i] == "/" ||
            tokens[i] == "*"
            ){
                if(tokens[i] == "+"){
                    int res = 0;
                        for(int i=0; i<2; i++){
                           res += st.top();
                           st.pop(); 
                           
                        }
                        st.push(res);
                }else if(tokens[i] == "*"){
                    int res = 1;
                        for(int i=0; i<2; i++){
                           res *= st.top();
                           st.pop(); 
                            
                        }
                        st.push(res);
                }else if(tokens[i] == "/"){
                    int den = st.top();
                    st.pop(); 
                    int num = st.top();
                    st.pop();

                    st.push((int)num/den); 
                    
                }else if(tokens[i] == "-"){
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    st.push(b-a);
                }
                
            }else{
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};


