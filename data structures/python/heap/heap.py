class Heap:
    def __init__(self, data, type):
        self.data = data if data is not None else []
        self.type = type.lower()

    def push(self, val):
        self.data.append(val)
        self._bubble_up(len(self.data) - 1)

    def _bubble_up(self, index):
        if index == 0:
            return

    def _parent(self, index):
        return (index - 1) // 2

    def _left(self, index):
        return 2 * index + 1

    def _right(self, index):
        return 2 * index + 2

    def _swap(self, i, j):
        self.data[i], self.data[j] = self.data[j], self.data[i]

    def _compare(self, i, j):
        if self.type == "min":
            return self.data[i] < self.data[j]
        else:
            return self.data[i] > self.data[j]
