from stack import Stack


def main():
    s = Stack(3)  # create stack with capacity 3

    # push some elements
    s.push(1)
    s.push(2)
    s.push(3)

    # this will raise OverflowError
    try:
        s.push(4)
    except OverflowError as e:
        print("OverflowError caught:", e)

    # pop all elements
    while not s.is_empty():
        print("Popped:", s.pop())

    # this will raise IndexError
    try:
        s.pop()
    except IndexError as e:
        print("IndexError caught:", e)


if __name__ == "__main__":
    main()
