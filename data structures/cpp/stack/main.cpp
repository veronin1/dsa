#include <iostream>
#include <stdexcept>
#include <string>

#include "stack.hpp"

int main() {
  Stack<std::string> stack;

  std::cout << "Pushing strings...\n";
  stack.push("apple");
  stack.push("banana");
  stack.push("cherry");
  stack.push("date");

  std::cout << "Stack size: " << stack.size() << "\n";

  std::cout << "Popping two elements:\n";
  std::cout << stack.pop() << "\n";
  std::cout << stack.pop() << "\n";

  std::cout << "Stack size after popping: " << stack.size() << "\n";

  std::cout << "Pushing elderberry and fig...\n";
  stack.push("elderberry");
  stack.push("fig");

  std::cout << "Popping remaining elements:\n";
  while (!stack.isEmpty()) {
    std::cout << stack.pop() << "\n";
  }

  std::cout << "Trying to pop from empty stack...\n";
  try {
    stack.pop();
  } catch (const std::out_of_range &e) {
    std::cout << "Caught exception: " << e.what() << "\n";
  }

  return 0;
}
