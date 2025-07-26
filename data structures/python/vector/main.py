from vector import Vector


def main():
    v = Vector()

    print("Is empty?", v.is_empty())  # True

    # Push values
    v.push_back(10)
    v.push_back(20)
    v.push_back(30)

    print("Vector contents:")
    v.print_vector()  # 10, 20, 30

    print("Front:", v.front())  # 10
    print("Back:", v.back())  # 30
    print("Size:", len(v))  # 3

    # Pop value
    popped = v.pop_back()
    print("Popped:", popped)  # 30

    print("After pop:")
    v.print_vector()  # 10, 20

    # Resize to 5
    v.resize(5)
    print("After resize to 5:")
    v.print_vector()  # 10, 20, None, None, None

    # Clear vector
    v.clear()
    print("After clear:")
    print("Is empty?", v.is_empty())  # True


if __name__ == "__main__":
    main()
