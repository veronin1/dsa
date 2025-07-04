# LinkedList (Python)

A linked list is a dynamic data structure where each element (node) contains a value and a reference to the next node in the sequence. This Python implementation provides fundamental functionalities for managing a singly linked list, including insertion, deletion, traversal, and utility operations.

## Interface

The linked list is managed through the following methods:

- `push_back(value)`: Adds the element `value` to the end of the linked list.
- `push_front(value)`: Inserts the element `value` at the beginning of the linked list.
- `print_list()`: Prints the entire linked list from beginning to end.
- `pop_back()`: Removes and returns the last element from the linked list.
- `pop_front()`: Removes and returns the first element from the linked list.
- `front()`: Returns the first element without removing it.
- `back()`: Returns the last element without removing it.
- `empty()`: Returns `True` if the list is empty, otherwise `False`.
- `clear()`: Removes all elements from the linked list, leaving it empty.
- `len()`: Returns the current number of elements in the linked list.
- `remove_value(value)`: Removes the first occurrence of `value` from the linked list.

## Usage

```py
from linkedlist import LinkedList

def main():
    # Create LinkedList instance
    lst = LinkedList()

    # Push elements front and back
    lst.push_front(2)      # List: 2
    lst.push_front(99)     # List: 99 -> 2
    lst.push_back(3)       # List: 99 -> 2 -> 3
    lst.push_back(5)       # List: 99 -> 2 -> 3 -> 5

    print("Initial list:")
    lst.print_list()

    # Access front and back elements
    print("Front element:", lst.front())
    print("Back element:", lst.back())

    # Pop elements from front and back
    print("Pop front:", lst.pop_front())
    print("Pop back:", lst.pop_back())

    print("List after popping front and back:")
    lst.print_list()

    # Check size and emptiness
    print("Size:", len(lst))
    print("Is empty?", lst.empty())

    # Add more elements
    lst.push_back(10)
    lst.push_back(20)
    lst.push_back(30)

    print("List before removing value 20:")
    lst.print_list()

    # Remove a value
    lst.remove_value(20)

    print("List after removing value 20:")
    lst.print_list()

    # Clear list
    lst.clear()

    print("List after clear:")
    lst.print_list()

    print("Is empty after clear?", lst.empty())

if __name__ == "__main__":
    main()
```
