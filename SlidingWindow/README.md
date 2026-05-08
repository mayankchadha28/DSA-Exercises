# Sliding Window

Sequential iteration over **contiguous** elements — strings, arrays, linked lists.

## Question Types

`min/max` · `longest/shortest` · `contained` · `running avg`

## Variants

### Fixed Length
Window size K stays constant.
> Max sum subarray of size K

### Dynamic Length
Expand right pointer, shrink left pointer.
> Smallest sum ≥ S

### Dynamic + Auxiliary Structure
Hashmap/hashset to track frequency while window grows/shrinks.
> Longest substring with ≤ K distinct chars · String permutation check