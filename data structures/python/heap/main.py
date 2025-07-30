from heap import Heap


def main():
    print("Testing Min-Heap:")
    min_heap = Heap(type="min")
    for num in [5, 3, 8, 1, 2]:
        print(f"Pushing {num}")
        min_heap.push(num)

    while not min_heap.empty():
        print(f"Popped: {min_heap.pop()}")

    print("\nTesting Max-Heap:")
    max_heap = Heap(type="max")
    for num in [5, 3, 8, 1, 2]:
        print(f"Pushing {num}")
        max_heap.push(num)

    while not max_heap.empty():
        print(f"Popped: {max_heap.pop()}")


if __name__ == "__main__":
    main()
