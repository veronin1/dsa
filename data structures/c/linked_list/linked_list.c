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

int main(void) {
    LinkedList* list = createLinkedList();
    pushBack(list, 3);

    Node* current = list->head;
    while (current != NULL) {
        printf("%i\n", current->data);
        current = current->next;
    }
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
}