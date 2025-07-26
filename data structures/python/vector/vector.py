class Vector:
    def __init__(self, data=None):
        if data is None:
            self.data = []
        else:
            self.data = data

        self.currentSize = len(self.data)
        self.capacity = len(self.data)

    def print_vector(self):
        for i, x in enumerate(self.data):
            print(x, end="")
            if i != self.currentSize - 1:
                print(", ", end="")
        print()

    def is_empty(self):
        return self.currentSize == 0

    def __len__(self):
        return self.currentSize

    def clear(self):
        self.data = []
        self.currentSize = 0
        self.capacity = 0

    def resize(self, newSize):
        self.data = self.data[:newSize]

        if newSize > self.currentSize:
            while len(self.data) < newSize:
                self.data.append(None)
        self.capacity = newSize
        self.capacity = max(self.capacity, newSize)

    def destroy_vector(self):
        self.data.clear()
        self.currentSize = 0
        self.capacity = 0

    def push_back(self, value):
        self.data.append(value)
        self.currentSize += 1
        self.capacity = max(self.capacity, self.currentSize)

    def front(self):
        if self.is_empty():
            return None
        return self.data[0]

    def back(self):
        if self.is_empty():
            return None
        return self.data[self.currentSize - 1]

    def pop_back(self):
        if self.is_empty():
            return None
        self.currentSize -= 1
        self.data.pop()
