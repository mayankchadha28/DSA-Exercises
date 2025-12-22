# Binary Search

## Definition

It is a Searching Algorithm used in a `Sorted Array` to search for a value i.e the target value. It works by checking the value in the center at each iteration and reduces the search by half.

- If the value is found, return the index of the value.
- If the target value is lower, search the left. 
- If the target value is high, search the right.


## Steps

1. Check the value in the center of Array.
2. If the target value is low, Search left half
If the taget value is high, search right half
3. Loop between the steps 1 and 2 until value is found.
4. Return the value. if not found return -1 or false


## Conditions
- Array must always be sorted

## Applications
- Searching Files in the OS - Here binary search may help to increase the efficiency of the search.
- Search for usernames on social media application.

## Time Complexity 

log(n)

more details on complexity updating soon.

## Generic Template

```
def binary_search(lo, hi, condition):

    while lo <= hi:
        mid = (lo+hi) // 2
        result = condition(mid)

        if result == "found":
            return mid
        elif result == "left":
            hi = mid - 1
        else:
            lo = mid + 1
    
    return -1

```


## Video Demonstration
[Working of Binary Search Algorithm](https://www.youtube.com/watch?v=eVuPCG5eIr4)



