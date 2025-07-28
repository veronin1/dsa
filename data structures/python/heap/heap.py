class Heap:
    def __init__(self, data):
        self.data = data

    def push(self, val):
        self.data.append(val)
        self._bubble_up(len(self.data) - 1)

    def _bubble_up(self, index):
        if index == 0:
            return
