#include <stdio.h>
#include <stdlib.h>

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
int size(LinkedList* list);
int front(LinkedList* list);
int back(LinkedList* list);
int empty(LinkedList* list);

int main(void) {
    LinkedList* list = createLinkedList();
    pushFront(list, 2);
    pushFront(list, 99);
    pushBack(list, 3);
    pushBack(list, 5);

    printList(list);
    printf("%i", back(list));
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

// Adds the element `value` to the end of the linked list
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

// Inserts the element `value` at the beginning of the linked list
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

// Prints the entire linked list from beginning to end.
void printList(LinkedList* list) {
    Node* current = list->head;

    while (current != NULL) {
        printf("%i\n", current->data);
        current = current->next;
    }
}

//  Returns the current number of elements in the linked list.
int size(LinkedList* list) {
    if (list == NULL) {
        return 0;
    }
    return list->size;
}

// Returns the first element without removing it.
int front(LinkedList* list) {
    if (list == NULL) {
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
    if (list == NULL) {
        return 1;
    }

    if (list->size > 0 || list->head != NULL) {
        return 0;
    } else {
        return 1;
    }
}
