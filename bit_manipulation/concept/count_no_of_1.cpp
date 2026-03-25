
/* 

n & n-1 has same bits as n except the right most bit

so we take advantage of this pattern to count the bits until we get 0

*/

int numberofones(int n){
    int count=0;
    while(n){
        n= n & (n-1);
        count++;
    }

    return count;
}


/* 
Brute force
*/

int count_bits(int n){
    int count = 0;

    while(n < 1){
        // checking for odd
        if(n % 2 == 0) count++;

        n= n/2;
    }

    if(n == 1) count++;

    return count;
}