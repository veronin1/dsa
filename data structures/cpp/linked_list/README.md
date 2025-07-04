# LinkedList (C++)

A **linked list** is a dynamic data structure where each element (node) contains a value and a pointer to the next node in the sequence. This implementation uses modern C++ features such as `std::unique_ptr` for memory safety and automatic resource management.

## Interface

The linked list is managed through the following methods:

- `void pushBack(int value)`: Adds the element `value` to the end of the linked list.
- `void pushFront(int value)`: Inserts the element `value` at the beginning of the linked list.
- `void printList() const`: Prints the linked list from beginning to end.
- `int popBack()`: Removes and returns the last element of the list. Throws if the list is empty.
- `int popFront()`: Removes and returns the first element of the list. Throws if the list is empty.
- `int front() const`: Returns the first element without removing it. Throws if the list is empty.
- `int back() const`: Returns the last element without removing it. Throws if the list is empty.
- `bool empty() const`: Returns `true` if the list is empty, otherwise `false`.
- `void clear()`: Removes all elements from the list.
- `int getSize() const`: Returns the current number of elements in the list.
- `void removeValue(int value)`: Removes the first occurrence of `value` from the list. Throws if the value is not found.

## Usage

```cpp
int main() {
  LinkedList list;

  list.pushFront(33);
  list.pushFront(50);
  list.pushFront(21);

  list.printList(); // Output: 21, 50, 33

  list.removeValue(50);
  list.printList(); // Output: 21, 33

  return 0;
}
```
