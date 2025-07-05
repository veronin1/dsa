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
            print(x, end='')
            if i != self.currentSize - 1:
                print(', ', end='')
        print()


def main():
    data = [3, 5, 9]
    v = Vector(data)

    v.print_vector()

if __name__ == "__main__":
    main()
