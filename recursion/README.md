## Recursion

Recursive functions are functions that call themselves
they also have a base case stating how shoukd the program terminate

example
```
void printNums()(int n){
    if(n == 1){
        cout << "1\n";
        return;
    }

    cour << n << " ";
    printNums(n-1);
}

```