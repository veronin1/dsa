# Vector (C++)

A vector is a dynamic array structure that automatically grows and shrinks in size as elements are added or removed.

## Interface

The vector can be interfaced through the following functions:

- `Vector()`: Creates an empty vector with a default capacity.
- `Vector(const int* arr, int size)`: Creates a vector from an existing array.
- `int size() const`: Returns the number of elements currently in the vector.
- `bool empty() const`: Returns `true` if the vector contains no elements.
- `int& front()`: Returns a reference to the first element. Throws if empty.
- `int& back()`: Returns a reference to the last element. Throws if empty.
- `void pushBack(const int& value)`: Appends a value to the end.
- `int popBack()`: Removes and returns the last element. Throws if empty.
- `void resize(size_t newCapacity)`: Resizes the internal array to `newCapacity`.
- `void clear()`: Clears all elements and frees internal memory.

## Compilation

To compile and run:

```sh
g++ -std=c++17 -o vector main.cpp
./vector
```

## Usage

```cpp
#include <iostream>
#include "vector.hpp"

int main() {
    Vector v;

    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    std::cout << "Front: " << v.front() << "\n"; // 1
    std::cout << "Back: " << v.back() << "\n";   // 3
    std::cout << "Size: " << v.size() << "\n";   // 3

    int removed = v.popBack();                   // removes 3
    std::cout << "Popped: " << removed << "\n";

    v.resize(10);
    std::cout << "Resized. Size: " << v.size() << "\n";

    v.clear();
    std::cout << "Cleared. Is empty: " << v.empty() << "\n";

    return 0;
}
```
