# Linked List

A linear data structure where each **node** holds a value and a pointer to the next node.

The first step in linked list is to preserve the address of next node. this is to avoid loosing the address.

```
Head
  │
  ▼
┌───────┬──────┐     ┌───────┬──────┐     ┌───────┬──────┐
│  val  │ next │────▶│  val  │ next │────▶│  val  │ next │────▶ null
│  42   │ ptr  │     │  17   │ ptr  │     │  93   │ null │
└───────┴──────┘     └───────┴──────┘     └───────┴──────┘
  Node 1                Node 2                Node 3
```

---

## Types

| Type | Description |
|---|---|
| Singly | Each node points forward only |
| Doubly | Each node points forward and backward |
| Circular | Tail points back to head |

---

## Time Complexity

| Operation | Complexity |
|---|---|
| Access / Search | O(n) |
| Insert / Delete at head | O(1) |
| Insert / Delete elsewhere | O(n) |

**Space:** O(n)

---

## Key Operations

- **Insert** – at head O(1), at tail/mid O(n)
- **Delete** – unlink the node by updating pointers
- **Search** – linear traversal from head
- **Reverse** – flip all next pointers

---

## Pros & Cons

✅ Dynamic size, O(1) head insert/delete  
❌ No random access, extra pointer memory, poor cache locality

---

## When to Use

- Frequent insertions/deletions at the front
- Unknown or frequently changing data size
- Implementing stacks, queues, or adjacency lists