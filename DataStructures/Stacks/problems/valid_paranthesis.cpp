#include <iostream>

using namespace std;


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
