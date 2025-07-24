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

#endif