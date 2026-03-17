


/* 
idea is to convert the power into binary form.
dec needs n digits
binary needs log2n+1 no of digits
which is optimized

5 = 101 
so we take the digit and multiply by value x

we are using binary as binary works we will be multiplying x by x times on each iteration so next time
x= x * x;
x^2 = x^2 * x^2
x^4 = x^4 * x^4
*/

double myPow(double x, int n) {

        // corner cases
        if(n == 0) return 1.0;
        if(x == 0) return 0.0;
        if(x == 1) return 1.0;
        if(x == -1 && n%2 == 0) return 1.0;
        if(x == -1 && n%2 != 0) return -1.0;


        long binForm = n;
        // if n is -1
        if(n < 0){
            x= 1/x;
            binForm = -binForm;
        }

        double ans = 1;

        while(binForm > 0){
            if(binForm % 2 == 1){
                ans *= x;
            }
            x *= x;
            binForm /= 2;
        }

        return ans;
        
    }