#include <iostream>
#include <vector>

using namespace std;

/* 

Reverse a string using 2 pointer approach - Similar to arrays
Both character & string methods  

{h, e, l, l, o, \0}
st index - 0 
end index - n-1 as n is null pointer

*/
void reverseString_char(vector<char>& s) {
    int n = s.size();

    int st = 0;
    int end = n-1;

    while(st<end){
        swap(s[st++], s[end--]);
    }
}

void reverseString_str(vector<char>& s) {
    string str = "hello world";

    reverse(str.begin(), str.end()); //iterators
    cout << str << endl;
}

int main(){



    return 0;

}