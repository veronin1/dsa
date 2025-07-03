class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self, head=None, size=0):
        self.head = None
        self.size = 0

    # Adds the element `value` to the end of the linked list
    def push_back(self, value):
        new_node = Node(value)

        if not self.head:
            self.head = new_node
        else:
            current = self.head
            while current.next is not None:
                current = current.next
            current.next = new_node

        self.size += 1
        return

    # Inserts the element `value` at the beginning of the linked list
    def push_front(self, value):
        new_node = Node(value)
        new_node.next = self.head
        self.head = new_node
        self.size += 1
        return

    # Prints the entire linked list from beginning to end
    def print_list(self):
        current = self.head
        while current is not None:
            print(current.data)
            current = current.next
        return

    # Removes and returns the last element from the linked list
    def pop_back(self):
        if not self.head:
            return None

        if self.head.next is None:
            back = self.head.data
            self.head = None
            self.size -= 1
            return back

        current = self.head
        while current.next.next is not None:
            current = current.next
        back = current.next.data
        current.next = None
        self.size -= 1
        return back

    # Removes and returns the first element from the linked list
    def pop_front(self):
        if not self.head:
            return None

        front = self.head.data
        self.head = self.head.next
        self.size -= 1
        return front

    # Returns the first element without removing it
    def front(self):
        if not self.head:
            return None
        return self.head.data

    # Returns the last element without removing it
    def back(self):
        if not self.head:
            return None

        current = self.head
        while current.next is not None:
            current = current.next
        return current.data

    # Returns true if the list is empty, otherwise false
    def empty(self):
        return not self.head

    # Removes all elements from the list (Python does this for you)
    def clear(self):
        self.head = None
        self.size = 0
        return

    # Returns the current number of elements in the list
    def __len__(self):
        return self.size

    # Removes the first occurence of value from the linked list
    def remove_value(self, value):
        if not self.head:
            return

        if self.head.data == value:
            self.head = self.head.next
            self.size -= 1
            return

        prev = self.head
        current = self.head.next

        while current:
            if current.data == value:
                prev.next = current.next
                self.size -= 1
                return
            prev = current
            current = current.next


def main():
    list = LinkedList()

    list.push_front(2)  # List: 2
    list.push_front(99)  # List: 99, 2
    list.push_back(3)  # List: 99, 2, 3
    list.push_back(5)  # List: 99, 2, 3, 5

    print("Initial list:")
    list.print_list()

    print("Front element:", list.front())
    print("Back element:", list.back())

    print("Pop front:", list.pop_front())
    print("Pop back:", list.pop_back())

    print("List after popping front and back:")
    list.print_list()

    print("Size:", len(list))
    print("Is empty?", list.empty())

    # Add a few more elements
    list.push_back(10)
    list.push_back(20)
    list.push_back(30)

    print("List before removing value 20:")
    list.print_list()

    list.remove_value(20)

    print("List after removing value 20:")
    list.print_list()

    list.clear()
    print("List after clear:")
    list.print_list()

    print("Is empty after clear?", list.empty())


if __name__ == "__main__":
    main()
