#include "linkedlist.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

LinkedList* createLinkedList() {
  LinkedList* list = malloc(sizeof(LinkedList));
  if (list == NULL) {
    return NULL;
  }
  list->head = NULL;
  list->size = 0;
  return list;
}

// Inserts element at the end of the linked list
void pushBack(LinkedList* list, int value) {
  Node* node = malloc(sizeof(Node));
  if (node == NULL) {
    return; // Memory allocation failed
  }
  node->data = value;
  node->next = NULL;

  if (list->head == NULL) {
    // If list is empty, new node becomes the head
    list->head = node;
  } else {
    // Traverse to the end and add the node
    Node* current = list->head;
    while (current->next != NULL) {
      current = current->next;
    }

    current->next = node;
  }

  // Keep track of list size
  list->size++;
}

// Inserts element at the beginning of the linked list
void pushFront(LinkedList* list, int value) {
  Node* node = malloc(sizeof(Node));
  if (node == NULL) {
    return; // Memory allocation failed
  }
  node->data = value;
  node->next = NULL;

  node->next = list->head;
  list->head = node;

  // Keep track of list size
  list->size++;
}

// Prints the entire linked list from beginning to end
void printList(LinkedList* list) {
  Node* current = list->head;

  while (current != NULL) {
    printf("%i", current->data);
    if (current->next != NULL) {
      printf(", ");
    }
    current = current->next;
  }
  printf("\n");
}

//  Removes and returns the last element from the list
int popBack(LinkedList* list) {
  if (list == NULL || list->head == NULL) {
    return -1;
  }

  // If list has only 1 element
  int back = 0;
  if (list->head->next == NULL) {
    back = list->head->data;
    free(list->head);
    list->head = NULL;
    list->size = 0;
    return back;
  }

  Node* current = list->head;
  while (current->next->next != NULL) {
    current = current->next;
  }
  back = current->next->data;
  free(current->next);
  current->next = NULL;
  list->size--;
  return back;
}

// Removes and returns the first element from the list
int popFront(LinkedList* list) {
  if (list == NULL || list->head == NULL) {
    return -1;
  }

  int front = list->head->data;
  Node* temp = list->head->next;
  free(list->head);
  list->head = temp;
  list->size--;
  return front;
}

// Returns the first element without removing it
int front(LinkedList* list) {
  if (list == NULL || list->head == NULL) {
    return -1;
  }
  return list->head->data;
}

// Return the last element without removing it
int back(LinkedList* list) {
  if (list == NULL) {
    return -1;
  }

  if (list->head == NULL) {
    return -1;
  }

  Node* current = list->head;
  while (current->next != NULL) {
    current = current->next;
  }

  return current->data;
}

// Returns 1 if list is empty, otherwise 0
int empty(LinkedList* list) {
  if (list == NULL) return 1;
  return (list->size == 0);
}

// Removes all elements from the linked list, leaving it empty
void clear(LinkedList* list) {
  if (list == NULL) {
    return;
  }

  Node* current = list->head;
  while (current != NULL) {
    Node* temp = current->next;
    free(current);
    current = temp;
  }
  list->head = NULL;
  list->size = 0;
}

//  Returns the current number of elements in the linked list
int size(LinkedList* list) {
  if (list == NULL) {
    return 0;
  }
  return list->size;
}

// Removes the first occurrence of 'value' from the linked list
void removeValue(LinkedList* list, int value) {
  if (list == NULL || list->head == NULL) {
    return;
  }

  Node* current = list->head;
  Node* prev = NULL;
  while (current != NULL) {
    if (current->data == value) {
      if (prev == NULL) {
        list->head = current->next;
      } else {
        prev->next = current->next;
      }
      free(current);
      list->size--;
      return;
    }
    prev = current;
    current = current->next;
  }
}
