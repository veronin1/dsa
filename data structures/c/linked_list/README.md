# LinkedList (C)

A linked list is a dynamic data structure where each element (node) contains a value and a pointer to the next node in the sequence. This C implementation provides basic functionality for managing a singly linked list, including insertion, deletion, traversal, and utility operations.

# Interface

The linked list is managed through the following functions:

- `void pushBack(LinkedList* list, int value)`: Adds the element `value` to the end of the linked list.
- `void pushFront(LinkedList* list, int value)`: Inserts the element `value` at the beginning of the linked list.
- `void printList(LinkedList* list)`: Prints the entire linked list from beginning to end.
- `int popBack(LinkedList* list)`: Removes and returns the last element from the linked list.
- `int popFront(LinkedList* list)`: Removes and returns the first element from the linked list.
- `int front(LinkedList* list)`: Returns the first element without removing it.
- `int back(LinkedList* list)`: Returns the last element without removing it.
- `int empty(LinkedList* list)`: Returns `1` if the list is empty, otherwise `0`.
- `void clear(LinkedList* list)`: Removes all elements from the linked list, leaving it empty.
- `int size(LinkedList* list)`: Returns the current number of elements in the linked list.
- `void remove_value(LinkedList* list, int value)`: Removes the first occurrence of `value` from the linked list.

## Compiling

Compile:

```sh
gcc main.c linkedlist.c -o linked_list -std=c11
```

Run:

```sh
./linked_list
```

## Usage

```c
#include <stdio.h>
#include "linkedlist.h"

int main() {
  LinkedList* list = createLinkedList();

  pushFront(list, 33);
  pushFront(list, 50);
  pushFront(list, 21);

  printList(list); // Output: 21, 50, 33

  removeValue(list, 50);
  printList(list); // Output: 21, 33

  clear(list); // Clean up before exiting
  free(list);  // Free the list structure itself

  return 0;
}
```
