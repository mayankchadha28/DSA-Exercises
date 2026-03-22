# Recursion

A function that **calls itself** with a **base case** to terminate.

```cpp
void printNums(int n) {
    if (n == 1) { cout << "1\n"; return; }  // base case
    cout << n << " ";
    printNums(n - 1);  // recursive call
}
```

---

## Key Concepts

**Call Stack** — each call is pushed onto the stack until the base case is hit.
```
main → f(4) → f(3) → f(2) → f(1)   ← hits base case
            ↑___backtrack______________|
```

**Backtracking** — once the base case returns, execution unwinds back through each call in reverse.

---

## Recurrence Relation

```
T(n) = O(1) + T(n-1)
```

---

## Time Complexity

**Method 1 — Expand the relation:**
```
T(n)   = k + T(n-1)
T(n-1) = k + T(n-2)
  ...
T(1)   = k
─────────────────────
T(n)   = k·n  →  O(n)
```

**Method 2 — Recursion tree** *(preferred)*:
```
TC = (no. of calls) × (work per call) = n × k = O(n)
```

---

## Space Complexity

```
SC = (depth of recursion tree) × (memory per call) = n × k = O(n)
```

Space is dominated by the **call stack**, not variables.