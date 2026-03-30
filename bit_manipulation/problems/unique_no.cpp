/* 
Unique no in an array


use xor as it gives 0 vwhen values are same
0^0 = 0
1^1 = 0
1^0 = 1
0^1 = 1

*/

int unique(int arr[], int n){
    int xorsum = 0;
    for(int i=0; i<n; i++){
        xorsum = xorsum^arr[i];
    }

    return xorsum;
}

/* 
2 unique nos in an array where all nos except two are present twice

if we have one in xor we know that in a position there is 1 in a no and other does not have it (use this property)
check in all nos who has set bit as 1 and xor


*/

int 2_unique(int arr[], int n){
    
}

int main(){
    int arr[] = {1, 2, 3, 4, 1, 2, 3};
    int arr2[] = {2, 4, 6, 7, 4, 5, 6, 2};
}