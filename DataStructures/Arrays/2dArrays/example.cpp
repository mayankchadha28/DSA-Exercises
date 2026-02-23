#include <iostream>

using namespace std;




int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int matrix[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}}; 
    //2D Array
    int rows = 4;
    int cols = 3;

    // Modifying an element
    matrix[2][1] = 18;

    // Accessing an element
    cout << matrix[2][1] << endl;

    /* 
    output all elements in a matrix
    */

    for(int i=0; i< rows; i++){ //i= row
        for(int j=0; i<cols;i++){ // j = col
            cout << matrix[i][j] << " ";
        }
        cout << endl; //each row different line
    }

    cout << endl;

    return 0;
}