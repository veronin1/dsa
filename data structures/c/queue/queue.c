#include "queue.h"

Queue createQueue(size_t capacity) {
  Queue q;

  if (capacity == 0) {
    capacity = 1000;
  }
  q.front = 0;
  q.rear = 0;
  q.capacity = capacity;
  q.data = malloc(sizeof(int) * q.capacity);
  if (q.data == NULL) {
    q.capacity = 0;
    return q;
  }
  return q;
}

bool isEmpty(Queue *q) {
  return q->size == 0;
}

size_t size(Queue *q) {
  return q->size;
}

void enqueue(Queue *q, int element) {
  if (q->size == q->capacity) {
    // queue full
    return;
  }

  q->data[q->rear] = element;
  q->rear = (q->rear + 1) % q->capacity;
  q->size++;
}
