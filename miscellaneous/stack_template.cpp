#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Stack{

private:

vector<T> vect;

public:

    Stack(){

    }

    void push(T val){
        vect.push_back(val);
    }

    void pop(){
        vect.pop_back();
    }

    T top(){
        return vect[vect.size()-1];
    }

    bool empty(){
        return vect.size() == 0;
    }

};


int main(){

    Stack<int>st;

    st.push(1);

    Stack<string>name_st;
    name_st.push("hello");

    return 0;
}