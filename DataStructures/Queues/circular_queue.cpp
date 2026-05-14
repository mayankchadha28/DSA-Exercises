#include <iostream>

using namespace std;

class CircularQueue{

    int* arr;
    
    int capacity, currSize;

    int f, r;


    public:

        CircularQueue(int size){
            capacity = size;
            arr = new int(capacity);

            f = 0;
            r = -1;
        }

        void push(int data){
            if(currSize == capacity){
                cout << "CQ is Full" << endl;
                return;
            }

            r = (r+1) % capacity;

            arr[r] = data;

        }

        void pop(){

            if(empty()){
                cout << "CQ is Empty" << endl;
                return;
            }

            f = (f+1) % capacity;
        }

        int front(){
            if(empty()){
                cout << "CQ is empty" << endl;
                return -1;
            }

            return arr[f];
        }

        bool empty(){
            return currSize == 0;
        }



};



int main(){


    return 0;
}