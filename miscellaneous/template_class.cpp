
#include <iostream>

using namespace std;

template <typename T, int Size>
class Array{

    

    public: 

        Array(){

        }

        T array[Size];

        void fillArr(T val){
            for(int i=0; i<Size; i++){
                array[i] = val;
            }
        }

        T& at(int index){
            return array[index];
        }

};


int main(){

    Array<string, 10>myArr;

    myArr.fillArr("Hello World!");

    cout << myArr.at(2) << endl;



    return 0;
}