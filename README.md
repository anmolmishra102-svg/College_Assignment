# College_Assignment
## Q1 – Complexity Analysis (Stack)

| Operation | Time | Space (extra) |
|-----------|------|---------------|
| PUSH(x)   | O(1) | O(1) |
| POP()     | O(1) | O(1) |
| PEEK()    | O(1) | O(1) |
| DISPLAY() | O(n) | O(1) |

Total space for the stack itself is O(n), where n is the capacity.

- PUSH, POP and PEEK only touch the `top` index, so they take constant time.
- DISPLAY visits every stored element once, so it is linear.

### What happens when a fixed-size stack gets too many elements?
With a fixed array, once `top == capacity - 1` the stack is full. Another PUSH would write outside the array (undefined behaviour / memory corruption / crash). To prevent this, the program checks `isFull()` first and prints **"Stack Overflow"** without inserting. Likewise, POP/PEEK on an empty stack (`top == -1`) report **"Stack Underflow"**.
Possible fixes: reject the insert (as done here), or use a dynamic array that doubles its capacity (push becomes amortized O(1), with an occasional O(n) resize).

## Q2 – Circular Queue

A normal array queue wastes freed space at the front. A circular queue wraps `front` and `rear` using `(index + 1) % capacity`, so space is reused.

**Full vs. empty:** when `front` and `rear` meet, both states look identical. This implementation uses a `count` variable:
- Empty: `count == 0`
- Full: `count == capacity`

(This also uses all `capacity` slots, unlike the "leave one slot empty" method.)

| Operation | Time | Space (extra) |
|-----------|------|---------------|
| ENQUEUE   | O(1) | O(1) |
| DEQUEUE   | O(1) | O(1) |
| FRONT     | O(1) | O(1) |
| DISPLAY   | O(n) | O(1) |
