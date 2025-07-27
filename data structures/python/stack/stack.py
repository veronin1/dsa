class Stack:
    def __init__(self, capacity):
        self.data = [None] * capacity
        self.capacity = capacity
        self.current_size = 0

    def push(self, element):
        if self.is_full():
            for i in range(1, self.capacity):
                self.data[i - 1] = self.data[i]
            self.data[self.capacity - 1] = element
        else:
            self.data[self.current_size] = element
            self.current_size += 1

    def pop(self):
        if self.is_empty():
            raise IndexError("Stack empty")
        self.current_size -= 1
        return self.data[self.current_size]

    def size(self):
        return self.current_size

    def is_empty(self):
        return self.current_size == 0

    def is_full(self):
        return self.current_size == self.capacity
