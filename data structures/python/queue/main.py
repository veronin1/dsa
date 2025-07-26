from queue import Queue

def main():
    q = Queue(3)
    for v in [10, 20, 30]:
        q.enqueue(v)

    print(q.front(), q.back(), q.size())  # 10 30 3

    print(q.dequeue())  # 10
    print(q.front())    # 20

    q.enqueue(40)
    print(q.back())     # 40

    try:
        q.enqueue(50)
    except OverflowError as e:
        print("Overflow:", e)

    while not q.isEmpty():
        print(q.dequeue())

    try:
        q.dequeue()
    except IndexError as e:
        print("Underflow:", e)

if __name__ == "__main__":
    main()
