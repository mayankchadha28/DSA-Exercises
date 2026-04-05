


#include <iostream>

using namespace std;


int max_row_sum(int matrix[][3],int row, int col){
    int max_sum = INT_MIN;
    for(int i=0; i<col; i++){
        int sum = 0;
        for(int j=0; j<row; j++){
            sum += matrix[i][j];
        }
        max_sum = max(sum, max_sum);
    }
    
    cout << "Max Row Sum: " << max_sum << endl;

    return max_sum;
}

int max_col_sum(int matrix[][3],int row, int col){
    int max_sum = INT_MIN;
    for(int i=0; i<row; i++){
        int sum = 0;
       for(int j=0; j< col; j++){
        //sum += matrix[j][i];
       }
    }

    cout << "Max Col Sum: " << max_sum << endl;

    return max_sum;
}

/* Primary Diagonal: from left to right */
int max_p_diag_sum(int matrix[][3],int n){
    int diag_sum = 0;
    for(int i=0; i<n; i++){
       for(int j=0; j< n; j++){
        if(i ==j){
            diag_sum += matrix[i][j];
        }
       }
    }

    cout << "Diagnoal Sum: " << diag_sum << endl;

    return diag_sum;
}

/* Secondary diagonal: from right to left */
int max_s_diag_sum(int matrix[][3], int n){

    int diag_sum = 0;
    for(int i = 0; i<n; i++){
        for(int j= n-1; j>0; j--){
            diag_sum += matrix[i][j];
        }
    }
    return diag_sum;

}

/* 
Sum of both primary diagnonal and secondary diagonal
One point to note here is in odd values they both share a variable 

TC - O(n2)
*/
int max_diag_sum(int matrix[][3], int n){

    int diag_sum = 0;
    for(int i=0; i< n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                diag_sum += matrix[i][j]; //primary
            }else if(j==n-1-i){ //handle the issue
                diag_sum += matrix[i][j]; //secondary
            }
        }
    }
    return diag_sum;
}


/* 
Sum of both primary diagnonal and secondary diagonal
Optimized

pd -> i==j
sd -> j =n-1-i
so we can remove 1 loop

TC - O(n)
*/
int max_diag_sum_optimised(int matrix[][3], int n){

    int diag_sum = 0;
    for(int i=0; i< n; i++){
        diag_sum += matrix[i][i];

        // to prevent common values from being added
        if(i != n-1-i){
            diag_sum+= matrix[i][n-1-i];
        }
    }
    return diag_sum;
}


int main(){

    int matrix[4][3] = {{1, 2, 3}, 
    {4, 5, 6}, 
    {7, 8, 9}};

    int row = 3, col=3;


    

    return 0;
}