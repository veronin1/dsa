class Stack:
    def __init__(self, capacity):
        self.data = [None] * maxSize
        self.capacity = capacity
        self.current_size = 0

    def push(self, element):
        if self.current_size == self.capacity:
            raise OverflowError("Stack is full")

        self.data[self.current_size] == element
        current_size += 1

    