class Vector:
    def __init__(self, data=None):
        if data is None:
            self.data = []
        else:
            self.data = data

        self.currentSize = len(self.data)
        self.capacity = len(self.data)

    def print_vector(self):
        for x in self.data:
            print(x)

def main():
    data = [3, 5, 9]
    v = Vector(data)

    v.print_vector()

if __name__ == "__main__":
    main()
