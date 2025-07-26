# Queue (Python)

A queue is a linear data structure that follows the First-In-First-Out (FIFO) principle. This Python implementation uses a circular buffer to efficiently manage enqueue and dequeue operations with a fixed maximum size.

## Interface

The queue provides the following methods:

- `enqueue(value)`: Adds `value` to the end of the queue. Raises `OverflowError` if the queue is full.
- `dequeue()`: Removes and returns the element from the front of the queue. Raises `IndexError` if the queue is empty.
- `front()`: Returns the element at the front without removing it. Raises `IndexError` if empty.
- `back()`: Returns the element at the back without removing it. Raises `IndexError` if empty.
- `isEmpty()`: Returns `True` if the queue is empty, else `False`.
- `size()`: Returns the current number of elements in the queue.

## Compilation

```bash
python main.py
```

## Usage

```py
from queue import Queue

def main():
    q = Queue(3)
    q.enqueue(10)
    q.enqueue(20)
    q.enqueue(30)
    print(q.front(), q.back(), q.size())  # 10 30 3

    print(q.dequeue())  # 10
    q.enqueue(40)

    while not q.isEmpty():
        print(q.dequeue())

if __name__ == "__main__":
    main()
```
