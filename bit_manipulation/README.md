## Bit Manipulation

### Right Shift (`>>`)

Shifts all bits `k` places to the right — equivalent to dividing by `2^k`.

```
x >> k  =  x / 2^k  (integer division)
```

#### Example

```
13 >> 3  →  1101 >> 3  →  0001  =  1
13 / 2³  =  13 / 8     =  1  ✓
```

#### Reference

| Expression | Result |
|------------|--------|
| `x >> 1`   | `x / 2`  |
| `x >> 2`   | `x / 4`  |
| `x >> k`   | `x / 2^k` |

> Remainders are discarded (floor division).

### Left Shift (`>>`)

Shifts all bits `k` places to the left

### Not (`~`)

