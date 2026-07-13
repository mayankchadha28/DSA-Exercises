

/* 
We solve the smallest problem and calculate f(n-1) and f(n-2)

for recursion we also need a base case

TC - O(2^N)
SC - O(N)

*/


int fib_rec(int n){

    if(n==0 || n==1){
        return n;
    }

    return fib_rec(n-1) + fib_rec(n-2);

}


/* 
For loop version
*/
int fib(int n) {
    if (n <= 1) return n;
       
        int a = 0, b=1;
        for(int i=2; i<=n; i++){
            int next = a + b;
            a = b;
            b = next;
        }

        return b;
}


int main(){




    return 0;
}