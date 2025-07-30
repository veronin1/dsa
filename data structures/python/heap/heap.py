class Heap:
    def __init__(self, data=None, type="min"):
        self.data = data if data is not None else []
        self.type = type.lower()

    def push(self, val):
        self.data.append(val)
        self._bubble_up(len(self.data) - 1)

    def pop(self):
        if not self.data:
            return None

        self._swap(0, len(self.data) - 1)
        root = self.data.pop()
        self._bubble_down_recursive(0)
        return root

    def _bubble_up(self, index):
        while index > 0:
            parent = self._parent(index)
            if self._compare(index, parent):
                self._swap(index, parent)
                index = parent
            else:
                break

    def _bubble_down_recursive(self, index):
        left = self._left(index)
        right = self._right(index)
        smallest = index

        if left < len(self.data) and self._compare(left, smallest):
            smallest = left

        if right < len(self.data) and self._compare(right, smallest):
            smallest = right

        if smallest != index:
            self._swap(index, smallest)
            self._bubble_down_recursive(smallest)

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

    def size(self):
        return len(self.data)

    def empty(self):
        return not self.data
