# Stack (C++)

A stack is a linear data structure that follows the Last In First Out (LIFO) principle. Elements are added (pushed) and removed (popped) from the top of the stack.

## Interface

The `Stack<T>` class provides the following public methods:

- `void push(T element)`: Adds an element to the top of the stack. If full, removes the oldest element.
- `T pop()`: Removes and returns the top element. Throws `std::out_of_range` if the stack is empty.
- `size_t size()`: Returns the number of elements in the stack.
- `bool isEmpty()`: Returns `true` if the stack is empty.
- `bool isFull()`: Returns `true` if the stack is full.

## Compilation

Compile:
```bash
g++ main.cpp -o stack -std=c++17
```

Run:
```bash
./stack
```

## Usage:

```cpp
int main() {
    Stack<std::string> stack;

    stack.push("apple");
    stack.push("banana");
    stack.push("cherry");

    std::cout << "Top item: " << stack.pop() << "\n"; // Output: cherry
    std::cout << "Stack size: " << stack.size() << "\n"; // Output: 2

    stack.push("date");
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << " ";
    }
    std::cout << "\n";

    return 0;
}
```


