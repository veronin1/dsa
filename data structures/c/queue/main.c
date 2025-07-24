#include <stdio.h>

#include "queue.h"

int main() {
  // Create queue with initial capacity 3
  Queue q = createQueue(3);

  // Enqueue some elements
  enqueue(&q, 10);
  enqueue(&q, 20);
  enqueue(&q, 30);

  printf("Front: %d\n", front(&q)); // Output: Front: 10
  printf("Back: %d\n", back(&q));   // Output: Back: 30
  printf("Size: %zu\n", size(&q));  // Output: Size: 3

  // Enqueue more to trigger resize
  enqueue(&q, 40);
  printf("After enqueue 40 (resize expected):\n");
  printf("Front: %d\n", front(&q)); // Output: Front: 10
  printf("Back: %d\n", back(&q));   // Output: Back: 40
  printf("Size: %zu\n", size(&q));  // Output: Size: 4

  // Dequeue elements
  printf("Dequeued: %d\n", dequeue(&q)); // Output: Dequeued: 10
  printf("Dequeued: %d\n", dequeue(&q)); // Output: Dequeued: 20

  printf("Front now: %d\n", front(&q)); // Output: Front now: 30
  printf("Size now: %zu\n", size(&q));  // Output: Size now: 2

  // Check empty
  printf("Empty? %d\n", isEmpty(&q)); // Output: Empty? 0

  // Dequeue remaining elements
  dequeue(&q);
  dequeue(&q);

  printf("Empty after dequeuing all? %d\n",
         isEmpty(&q)); // Output: Empty after dequeuing all? 1

  // Try dequeue on empty queue
  printf("Dequeue on empty queue: %d\n", dequeue(&q)); // Output: -1

  freeQueue(&q);

  return 0;
}
