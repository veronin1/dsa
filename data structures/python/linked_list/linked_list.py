class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self, head, size):
        self.head = None
        self.size = 0

def main():
    linked_list = LinkedList()