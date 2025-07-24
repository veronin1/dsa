#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

typedef struct {
  int *data;
  size_t front;
  size_t rear;
  size_t size;
  size_t capacity;
} Queue;

bool isEmpty(void);
int size(void);
void enqueue(int element);
int front(void);
int back(void);
int dequeue(void);

#endif