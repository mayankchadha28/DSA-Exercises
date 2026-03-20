#include <iostream>

using namespace std;

int main(){

    string num = "1101";
    int pow = 1;   
    int res = 0;
    for(int i=num.length()-1; i >= 0; i--){
        
        if(num[i] == '1') res = res + pow; 

        pow *= 2;
    }

    cout << "Decimal: " << res << endl;

    return 0;
}