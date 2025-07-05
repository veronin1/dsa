class Vector:
    def __init__(self, data, currentSize=0, capacity=0):
    if data is None:
        self.data = []
    else:
        self.data = data
        
    self.currentSize = 0
    self.capacity = 0

