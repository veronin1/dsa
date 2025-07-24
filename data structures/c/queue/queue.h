#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  int *data;
  size_t front;
  size_t rear;
  size_t size;
  size_t capacity;
} Queue;

Queue createQueue(size_t capacity);
bool isEmpty(Queue *q);
size_t size(Queue *q);
void enqueue(Queue *q, int element);
int front(Queue *q);
int back(Queue *q);
int dequeue(Queue *q);
void freeQueue(Queue *q);

#endif