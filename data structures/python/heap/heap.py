class Heap:
    def __init__(self, data):
        self.data = data

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
