class Stack:
    def __init__(self, *args):
        self.__list = list(args)
        self.__size = len(args)
    
    @property
    def top(self):
        if self.__size == 0:
            return None
        return self.__list[-1]
    
    def push(self, item):
        self.__list.append(item)
        self.__size += 1
    
    def pop(self):
        if self.__size == 0:
            return None
        self.__size -= 1
        return self.__list.pop()

    def __len__(self):
        return self.__size

# Tests:
assert Stack().top is None
assert Stack("a").top == "a"
assert Stack(1, 2, 3, 4, 5).top == 5
assert Stack(*list(range(1000))).top == 999

# pop
s = Stack("a", "b", "c", "d")
s.pop()
assert s.top == "c"
s.pop()
s.pop()
assert s.top == "a"
s.pop()
assert s.top is None

# push
s.push("X")
assert s.top == "X"
s.push("X")
s.push("X")
assert s.top == "X"

# len
assert len(s) == 3
s.pop(); s.pop(); s.pop()
assert len(s) == 0

"✅ All OK! +0.5 point"