from linkedlist import LinkedList


def main():
    # Create LinkedList instance
    lst = LinkedList()

    # Push elements front and back
    lst.push_front(2)  # List: 2
    lst.push_front(99)  # List: 99 -> 2
    lst.push_back(3)  # List: 99 -> 2 -> 3
    lst.push_back(5)  # List: 99 -> 2 -> 3 -> 5

    print("Initial list:")
    lst.print_list()

    # Access front and back elements
    print("Front element:", lst.front())  # Expected: 99
    print("Back element:", lst.back())  # Expected: 5

    # Pop elements from front and back
    print("Pop front:", lst.pop_front())  # Removes 99
    print("Pop back:", lst.pop_back())  # Removes 5

    print("List after popping front and back:")
    lst.print_list()  # Expected: 2 -> 3

    # Check size and emptiness
    print("Size:", len(lst))  # Expected: 2
    print("Is empty?", lst.empty())  # Expected: False

    # Add more elements
    lst.push_back(10)
    lst.push_back(20)
    lst.push_back(30)

    print("List before removing value 20:")
    lst.print_list()  # Expected: 2 -> 3 -> 10 -> 20 -> 30

    # Remove a value
    lst.remove_value(20)

    print("List after removing value 20:")
    lst.print_list()  # Expected: 2 -> 3 -> 10 -> 30

    # Clear list
    lst.clear()

    print("List after clear:")
    lst.print_list()  # Expected: (empty)

    print("Is empty after clear?", lst.empty())  # Expected: True


if __name__ == "__main__":
    main()
