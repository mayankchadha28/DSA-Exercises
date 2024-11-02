Note: - Before we begin it is important to note that Time Complexity is not equal to Time taken to execute the program
Time Complexity != Time taken to execute program

## Introduction

It is also called as Big O notation and is represented as O(n) where n is the complexity.

Time complexity is the number of operations needed to run an algorithm on large amounts of data. And the number of operations can be considered as time because the computer uses some time for each operation.

- It always considers the worst case scenario.
- Constants are always neglected

## Common Complexities
 - O(1) - Constant : It is called as constant time complexity. It means if the number of data changes. The execution time remains the same

 For Example: Left take a function and run it. the function prints 
 ```
 def Func(arr[]):
   print("Hello World) 
 
 ```
 This function is run for 10 data or 10 million data, the execution is constant

 - O(n) - Linear : Number of operations increases as the input size increases. 

 For example: Loop an Array

 - O(n <sup>2</sup>) - Quadratic : It is generally worst

 For example : Generally found in Nested Loops or Matrix


 - O(log n) : It is generally good and also found in binary search generally. The input size reduces by half on each iteration

 - O(n log n) - Generally found in sorting. 

 - O(2 <sup>n</sup>) - Exponential : Generally found in recursion. It is the worst

 ## Diagram

 ![Time Complexity](../../Images/timecomplexity.jpg)

 ## Common Cases

Here n is no of operations
Generally in programmming we consider it takes around 1 second to execute 10 <sup>8</sup> operations

 | Condition | Generally Considered Complexity | Considered Algorithm |
 |-----------| --------------------------------| -------------------- |
 | n > 10<sup>8</sup> | O(log n) or O(1) | |
 | n <= 10 <sup>8</sup> | O (n) | |
 | n <= 10<sup>6</sup> | O(n log n) | |
 | n <= 10<sup>4</sup> | O(n<sup>2</sup>) | |
 | n <= 500 | O(n<sup>3</sup>) | |
 | n <= 25 | O(2<sup>n</sup>) | |
 | n <= 12 | O(n!) | |





## References

- [W3Schools - Time Complexity](https://www.w3schools.com/dsa/dsa_timecomplexity_theory.php)
- [Timne COmplexity for coding interviews - Apna College Youtube](https://www.youtube.com/watch?v=5T0SiJocPCI)