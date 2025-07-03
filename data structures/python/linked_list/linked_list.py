class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self, head, size):
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
            self.head = None
            return None

        current = self.head
        while current.next.next is not None:
            current = current.next
        current.next = None
        self.size -= 1
        return
    
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


def main():
    linked_list = LinkedList()
