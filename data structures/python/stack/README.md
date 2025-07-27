# Stack (Python)

A stack is a linear data structure which follwos the Last-In-First-Out (LIFO) principle. This Python implementation uses a fixed-size list (array) to manage stack operations efficiently.

## Interface

The stack provides the following methods:

- `push(element)`: Adds an element to the top of the stack. If full, removes the oldest element.
- `pop()`: Removes and returns the top element. Throws `IndexError` if the stack is empty.
- `size()`: Returns the number of elements in the stack.
- `is_empty()`: Returns `True` if the stack is empty.
- `is_full()`: Returns `True` if the stack is full.

## Compilation

Run:

```sh
python main.py
```

## Usage

```python
from stack import Stack

def main():
    s = Stack(3)
    s.push(10)
    s.push(20)
    s.push(30)
    print(s.size())       # 3
    print(s.is_full())    # True

    try:
        s.push(40)
    except OverflowError as e:
        print("OverflowError caught:", e)

    while not s.is_empty():
        print(s.pop())

    try:
        s.pop()
    except IndexError as e:
        print("IndexError caught:", e)

if __name__ == "__main__":
    main()
```
