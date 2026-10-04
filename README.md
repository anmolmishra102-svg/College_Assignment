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
Stack Overflow
Since the stack has a fixed capacity of MAX = 5, the valid indices are 0 to 4.

When:

top == MAX - 1

the stack is full. If the user attempts another PUSH, Stack Overflow occurs.

For example:

[10] [20] [30] [40] [50]
                         ↑
                        top

Trying to insert 60 is rejected because there is no free position.

Stack Underflow
When:

top == -1

the stack is empty. Attempting POP() or PEEK() results in Stack Underflow.



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

Circular Queue vs. Linear Queue
1. Better utilization of memory
Consider a linear queue of size 5:

[10] [20] [30] [40] [50]
 ↑                   ↑
front               rear

After deleting the first three elements:

[  ] [  ] [  ] [40] [50]
             ↑     ↑
           front   rear

There are three unused positions at the beginning, but rear has already reached the last index.

A linear queue may therefore be unable to insert another element without shifting the existing elements.

A circular queue solves this by wrapping rear back to index 0:

[60] [70] [  ] [40] [50]
 ↑                   ↑
rear                front

Thus, previously unused positions can be reused.

2. Time complexity of ENQUEUE and DEQUEUE
Both operations take constant time:

ENQUEUE = O(1)

DEQUEUE = O(1)

No shifting of elements is required.

3. Space complexity
For an array of size MAX:

Queue storage = O(MAX)

Extra space per operation = O(1)

4. Problem when REAR reaches the last index
This problem is called false overflow.

For example:

MAX = 5

[  ] [  ] [30] [40] [50]
 ↑                   ↑
unused              rear

Although positions 0 and 1 are free, a simple linear queue considers the queue full because rear is at the last index.

A circular queue avoids this problem using:

rear = (rear + 1) % MAX;

When rear reaches the last position, it wraps around to 0.

## Final Comparison

| Feature | Linear Queue | Circular Queue |
|---|---|---|
| Principle | FIFO | FIFO |
| ENQUEUE | O(1) | O(1) |
| DEQUEUE | O(1) | O(1) |
| DISPLAY | O(n) | O(n) |
| Space Complexity | O(n) | O(n) |
| Memory Utilization | Less efficient | More efficient |
| Reuse of Empty Positions | No | Yes |
| Rear Movement | Moves only forward | Wraps around |
| False Overflow | Possible | Avoided |
| Implementation | Simpler | Slightly more complex |
| Full Condition | `rear == MAX - 1` | `(rear + 1) % MAX == front` |
| Empty Condition | `front > rear` / implementation dependent | `front == -1` |


Important conditions in the circular queue program:

// Empty
front == -1

// Full
(rear + 1) % MAX == front


