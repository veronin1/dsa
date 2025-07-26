class Stack:
    def __init__(self, capacity):
        self.data = [None] * maxSize
        self.capacity = capacity
        self.current_size = 0

    def push(self, element):
        if is_full:
            raise OverflowError("Stack is full")

        self.data[self.current_size] == element
        current_size += 1

    def pop():
        if is_empty:
            raise IndexError("Stack empty")
        self.current_size -= 1
        return self.data[self.current_size]


    