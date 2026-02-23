#include <iostream>

using namespace std;


bool linear_search(int matrix[][3], int rows, int cols, int key){
    for(int i=0; i<rows; i++){
        for(int j=0; i<cols; j++){
            if(matrix[i][j] == key){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int matrix[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}}; 
    //2D Array
    int rows = 4;
    int cols = 3;
    int key = 6;

    cout << linear_search(matrix, rows, cols, key) << endl;

    return 0;
}