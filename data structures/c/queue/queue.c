#include "queue.h"

Queue createQueue(size_t capacity) {
  Queue q;

  if (capacity == 0) {
    capacity = 1000;
  }
  q.front = -1;
  q.rear = -1;
  q.size = 0;
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
    resize(q, q->capacity * 2);
  }

  if (q->size == 0) {
    q->front = q->rear = 0;
  } else {
    q->rear = (q->rear + 1) % q->capacity;
  }

  q->data[q->rear] = element;
  q->size++;
}

void resize(Queue *q, size_t newCapacity) {
  int *tempArray = malloc(sizeof(int) * newCapacity);
  if (!tempArray) {
    return;
  }

  size_t limit = q->size > newCapacity ? newCapacity : q->size;

  for (size_t i = 0; i < limit; ++i) {
    tempArray[i] = q->data[(q->front + i) % q->capacity];
  }

  int *oldData = q->data;
  q->data = tempArray;
  q->capacity = newCapacity;
  q->size = limit;
  q->front = 0;
  q->rear = limit;

  free(oldData);
}

int front(Queue *q) {
  if (q->size == 0) {
    return -1;
  }
  return q->data[q->front];
}

int back(Queue *q) {
  int index = (q->rear - 1 + q->capacity) % q->capacity;
  return q->data[index];
}

// remove and return the value at front of q
int dequeue(Queue *q) {
  if (isEmpty(q)) {
    return -1;
  }
  int front = q->data[q->front];

  if (q->size == 1) {
    q->rear = q->front = -1;
  } else {
    q->front = (q->front + 1) % q->capacity;
  }

  q->size--;
  return front;
}

void freeQueue(Queue *q) {
  free(q->data);
  q->data = NULL;
  q->capacity = 0;
  q->front = -1;
  q->rear = -1;
  q->size = 0;
}
