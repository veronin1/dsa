class Vector {
 private:
  int *data;
  int currentSize;
  int capacity;

 public:
  Vector() : data(nullptr), currentSize(0), capacity(0) {}

  int size(void) { return currentSize; }
};