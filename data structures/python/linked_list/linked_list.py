class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self, head, size):
        self.head = None
        self.size = 0

    # Adds the element `value` to the end of the linked list.
    def push_back(self, value):
        new_node = Node(value)
        if not new_node:
            return
        new_node.data = value
        new_node.next = None

        if not self.head:
            self.head = new_node
        else:
            current = self.head
            while current.next is not None:
                current = current.next
            
            current.next = new_node
        
        self.size += 1

    # Inserts the element `value` at the beginning of the linked list
    def push_front(self, value):
        new_node = Node(value)
        if not new_node:
            return
        new_node.data = value
        new_node.next = self.head
        self.head = new_node
        self.size += 1

    def print_list(self):
        current = self.head
        while current is not None:
            print(current.data)




def main():
    linked_list = LinkedList()