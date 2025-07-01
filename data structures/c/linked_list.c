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

int main(void) {
    LinkedList* list = createLinkedList();
}

LinkedList* createLinkedList() {
    LinkedList* list = malloc(sizeof(LinkedList));
    if (list == NULL) {
        return NULL;
    }
    list->size = 0;
    return list;
}

void pushBack(LinkedList* list, int value) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        return;
    }
    node->data = value;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
    } else {
        Node* current = list->head;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = node;
    }
}