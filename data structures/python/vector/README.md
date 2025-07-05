# Vector (Python)

A vector in this context is a **dynamic array** data structure, much like a Python list, but implemented with explicit methods to manage its size and capacity. It offers more control over memory allocation compared to standard Python lists while maintaining similar functionality.

## Interface

The `Vector` class is managed through the following methods:

- `Vector(data=None)`: Initializes a new `Vector` instance. If `data` (an iterable) is provided, the vector is initialized with its elements. Otherwise, it starts empty.
- `print_vector()`: Prints all elements in the vector, separated by commas.
- `is_empty()`: Returns `True` if the vector contains no elements, otherwise `False`.
- `__len__()`: Returns the number of elements currently in the vector. This allows `len(my_vector)` to work.
- `clear()`: Removes all elements from the vector, effectively making it empty.
- `resize(newSize)`: Changes the number of elements in the vector to `newSize`. If `newSize` is smaller than the current size, elements are truncated. If `newSize` is larger, `None` values are appended to reach the new size.
- `destroy_vector()`: Clears all elements and resets the vector's size and capacity to zero.
- `push_back(value)`: Appends a new `value` to the end of the vector.
- `front()`: Returns the first element in the vector. Returns `None` if the vector is empty.
- `back()`: Returns the last element in the vector. Returns `None` if the vector is empty.
- `pop_back()`: Removes and returns the last element of the vector. Returns `None` if the vector is empty.

## Compilation

```sh
python main.py
```

## Usage

```python
# Create an empty vector
my_vector = Vector()

# Push some elements
my_vector.push_back(10)
my_vector.push_back(20)
my_vector.push_back(30)
print("Initial vector:", end=" ")
my_vector.print_vector() # Should print 10, 20, 30
print(f"Size: {len(my_vector)}, Capacity: {my_vector.capacity}")

# Check if empty
print(f"Is empty? {my_vector.is_empty()}")

# Resize down
my_vector.resize(2)
print("After resizing down to 2:", end=" ")
my_vector.print_vector() # Should print 10, 20
print(f"Size: {len(my_vector)}, Capacity: {my_vector.capacity}")

# Resize up
my_vector.resize(5)
print("After resizing up to 5:", end=" ")
my_vector.print_vector() # Should print 10, 20, None, None, None
print(f"Size: {len(my_vector)}, Capacity: {my_vector.capacity}")

# Access front and back elements
print(f"Front element: {my_vector.front()}") # Should print 10
print(f"Back element: {my_vector.back()}")   # Should print None

# Pop back
popped_value = my_vector.pop_back()
print(f"Popped value: {popped_value}") # Should print None
print("Vector after pop_back:", end=" ")
my_vector.print_vector() # Should print 10, 20, None, None

# Clear the vector
my_vector.clear()
print("Vector after clear:", end=" ")
my_vector.print_vector() # Should print nothing
print(f"Size: {len(my_vector)}, Capacity: {my_vector.capacity}")

# Destroy the vector
another_vector = Vector([1, 2, 3])
print("Another vector before destroy:", end=" ")
another_vector.print_vector()
another_vector.destroy_vector()
print("Another vector after destroy:", end=" ")
another_vector.print_vector()
print(f"Size: {len(another_vector)}, Capacity: {another_vector.capacity}")
```
