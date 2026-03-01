
/* 

generate all possible subset of a set
{a, b, c}

{} -        000
{c} -       001  
{b}         010
{b, c}      011
{a}         100
{a, c}      101
{a, b}      110
{a, b, c}   111

represent this with binary nos

nos are from 1-7

we can loop the value from 2^n -1

checkin i if jth bit is set or not

*/

void subsets(int arr[], int n){
    for(int i=0; i< (1<<n); i++){
        for(int j=0; j<n; j++){
            if( )
        }
    }
}