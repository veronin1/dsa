class Queue:
    def __init__(self, maxSize=1000):
        self.data = [None] * maxSize
        self.head = 0
        self.tail = -1
        self.currentSize = 0
        self.maxSize = maxSize

    def enqueue(self, value):
        if self.currentSize == self.maxSize:
            raise OverflowError("Queue is full")

        self.tail = (self.tail + 1) % self.maxSize
        self.data[self.tail] = value
        self.currentSize += 1

    def dequeue(self):
        if self.isEmpty():
            raise IndexError("Queue is empty")
        front = self.data[self.head]
        self.data[self.head] = None
        self.head = (self.head + 1) % self.maxSize
        self.currentSize -= 1
        return front

    def front(self):
        if self.isEmpty():
            raise IndexError("Queue is empty")
        return self.data[self.head]

    def back(self):
        if self.isEmpty():
            raise IndexError("Queue is empty")
        return self.data[self.tail]

    def isEmpty(self):
        return self.size() == 0

    def size(self):
        return self.currentSize
