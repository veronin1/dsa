#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct LinkedList {
  Node* head;
  int size;
} LinkedList;

LinkedList* createLinkedList();
void pushBack(LinkedList* list, int value);
void pushFront(LinkedList* list, int value);
void printList(LinkedList* list);
int popBack(LinkedList* list);
int popFront(LinkedList* list);
int front(LinkedList* list);
int back(LinkedList* list);
int empty(LinkedList* list);
void clear(LinkedList* list);
int size(LinkedList* list);
void removeValue(LinkedList* list, int value);

#endif