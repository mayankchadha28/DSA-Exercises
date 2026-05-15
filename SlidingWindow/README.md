# Sliding Window

Sequential iteration over **contiguous** elements (grouped together) — strings, arrays, linked lists.

## Question Types

`min/max` · `longest/shortest` · `contained` · `running avg`

## Variants

### Fixed Length
Window size K stays constant.
> Eg: Max sum subarray of size K

### Dynamic Length (Like a caterpillar)
Expand right pointer, shrink left pointer.
> Eg: Smallest sum ≥ value

### Dynamic + Auxiliary Structure
Hashmap/hashset to track frequency while window grows/shrinks.
> Longest substring with ≤ K distinct chars · String permutation check
> String purmutations