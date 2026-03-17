
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