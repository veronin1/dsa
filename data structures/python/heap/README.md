# Heap (Python)

A heap is a bianry tree-based structure used to efficiently get the minimum or maximum value. A heap is a priority queue where a certain type of value is always at the top. In a min-heap the smallest valeu is always at the top, and the opposite applies for a max-heap.

## Interface

The heap can be interfaced through the following methods:

* `__init__(data=None, type="min")`: Initializes a new heap. Accepts an optional list of data and the heap type (`"min"` or `"max"`).
* `push(val)`: Inserts a value into the heap and maintains the heap property.
* `pop()`: Removes and returns the top (min or max) value from the heap. Returns `None` if the heap is empty.
* `clear()`: Empties the heap completely.
* `size()`: Returns the number of elements currently in the heap.
* `empty()`: Returns `True` if the heap is empty, otherwise `False`.
* `_bubble_up(index)`: Moves the element at the given index up the heap until the heap property is restored.
* `_bubble_down_recursive(index)`: Recursively moves the element at the given index down the heap to maintain order.
* `_bubble_down_iterative(index)`: Iteratively does the same as `_bubble_down_recursive`, used as an alternative.
* `_parent(index)`: Returns the index of the parent node.
* `_left(index)`: Returns the index of the left child node.
* `_right(index)`: Returns the index of the right child node.
* `_swap(i, j)`: Swaps the elements at indices `i` and `j` in the heap.
* `_compare(i, j)`: Compares two elements based on heap type. Returns `True` if `i` has higher priority than `j`.

## Compilation & Run

```sh
python main.py
```

## Usage

```python
from heap import Heap

# Create a min-heap
min_heap = Heap(type="min")

# Add values
min_heap.push(5)
min_heap.push(2)
min_heap.push(8)

# Remove values in priority order
print(min_heap.pop())  # 2
print(min_heap.pop())  # 5
print(min_heap.pop())  # 8

# Max-heap example
max_heap = Heap(type="max")
for n in [1, 4, 3]:
    max_heap.push(n)

while not max_heap.empty():
    print(max_heap.pop())  # 4, 3, 1
```
