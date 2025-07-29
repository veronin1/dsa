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

        while index > 0:
            parent = self._parent(index)

            if self._compare(self.data[index], self.data[parent]):
                self._swap(index, parent)
                index = parent
            else:
                break

    def _bubble_down(self, index)
        left = self._left(index)
        right = self._right(index)
        smallest = 0

        if (self._compare(data[left], data[smallest]):
            smallest = left

        if (self._compare(data[right], data[smallest]):
            smallest = right

        self._swap(data[index], data[smallest])
        index = smallest
        

    def pop(self):
         front = data[0]
         data.remove(0)
         self._swap(front, data[0])
         self._bubble_down(len(self.data - 1)
    
            
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
