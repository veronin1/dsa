#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main(void) {
  LinkedList* list = createLinkedList();

  pushFront(list, 2);  // List: 2
  pushFront(list, 99); // List: 99, 2
  pushBack(list, 3);   // List: 99, 2, 3
  pushBack(list, 5);   // List: 99, 2, 3, 5

  printf("Initial list:\n");
  printList(list);

  printf("Front element: %d\n", front(list));
  printf("Back element: %d\n", back(list));

  printf("Pop front: %d\n", popFront(list));
  printf("Pop back: %d\n", popBack(list));

  printf("List after popping front and back:\n");
  printList(list);

  printf("Size: %d\n", size(list));
  printf("Is empty? %d\n", empty(list));

  // Add a few more elements
  pushBack(list, 10);
  pushBack(list, 20);
  pushBack(list, 30);

  printf("List before removing value 20:\n");
  printList(list);

  removeValue(list, 20);

  printf("List after removing value 20:\n");
  printList(list);

  clear(list);
  printf("List after clear:\n");
  printList(list);

  printf("Is empty after clear? %d\n", empty(list));

  free(list);

  return 0;
}
