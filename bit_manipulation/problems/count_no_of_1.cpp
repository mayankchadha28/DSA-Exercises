
/* 

Leetcode: https://leetcode.com/problems/number-of-1-bits/description

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
Odd number will always have the last bit set

*/

int numberofones_bruteforce(int n){
    int count = 0;
    
    while(n){
        count += (n & 1);
        n >>= 1;
    }
    
    return count;
}

int numberofones_bruteforce2(int n){
    int count = 0;

    while(n > 1){
        if ((n % 2) == 1){
            count++;
        }
        n= n/2;
    }

    if(n ==1) count++;

}

/* 
Brute force
*/

// int count_bits(int n){
//     int count = 0;

//     while(n < 0){
//         // checking for odd
//         if(n % 2 == 1) count++;

//         n= n/2;
//     }

//     if(n == 1) count++;

//     return count;
// }