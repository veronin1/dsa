# Vector (C)

A vector is a dynamic array data structure that allows for more efficient manuevearbility. It grows and shrinks automatically as elemnts are added or removed.

## Interface

The vector is managed through the following methods:

- `bool empty()`: Returns `1` if the list is empty, otherwise `0`.
- `int size()`: Return number of elements in the vector.
- `void clear()`: Removes all elements from the vector.
- `void push_back(int value)`: Appends a new element to the end of the vector.
- `int front()`: Returns a reference to the first element in the vector.
- `int back()`: Returns a reference to the last element in the vector.
- `int pop_back()`: Remove and return the last element of the vector.
- `void resize(int newSize)`: Changes the number of elements in the vector to `newSize`.
