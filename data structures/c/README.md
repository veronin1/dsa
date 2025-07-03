# LinkedList Interface (C)

The linked list is managed through the following functions:

- `void pushBack(LinkedList* list, int value)`: Adds the element `value` to the end of the linked list.

- `void pushFront(LinkedList* list, int value)`: Inserts the element `value` at the beginning of the linked list.

- `void printList(LinkedList* list)`: Prints the entire linked list from beginning to end.

- `int pop_back(LinkedList* list)`: Removes and returns the last element from the linked list. (TODO)

- `int pop_front(LinkedList* list)`: Removes and returns the first element from the linked list. (TODO)

- `int front(LinkedList* list)`: Returns the first element without removing it.

- `int back(LinkedList* list)`: Returns the last element without removing it.

- `int empty(LinkedList* list)`: Returns `1` if the list is empty, otherwise `0`.

- `void clear(LinkedList* list)`: Removes all elements from the linked list, leaving it empty.

- `int size(LinkedList* list)`: Returns the current number of elements in the linked list.

- `void remove_value(LinkedList* list, int value)`: Removes the first occurrence of `value` from the linked list.
