#include <iostream>

using namespace std;

int main(){

    string str = "";

    int n = 13;
    while(n!=0){
        if(n%2 == 1) str += '1';
        else str += '0';
        // str += to_string(n%2);
        n = n/2;
    }

    reverse(str.begin(), str.end());

    cout << "Binary: " << str << endl;

    return 0;

}