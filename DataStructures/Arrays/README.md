# Arrays 

## Definition

- Array is a Datastructure used to store multiple elements of similar type. 
- The memory is allocated in a contiguous order.
- The Index typically starts from 0

## Example

```
arr = ["Apple", "Banana", "Kiwi", "Mango", "Watermelon"]
```

This is an example of an 1D array with 5 elements. The first element will have an index of 0 i.e `Apple`


To create a 2D array

```
arr = [
    [1,2,3],
    [4,5,6],
    [7,8,9]
    ]
```
## SUB ARRAY
 - Max sub array - n(n+1)/2
 
 | start | end (start to (end - 1))|


## KADANE'S ALGORITHM
(+ve) + (+ve) -> +ve
-ve + (bigger number) +ve -> +ve
+ve + (bugger number) -ve -> +ve

Adding a large negative value reduces the sum. So instead of carrying forward a negative sum, it is better to reset the sum to zero.