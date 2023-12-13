class Version:
    def __init__(self, *args):
        if len(args) == 1:
            versions = args[0].split('.')
            self.mjr = int(versions[0])
            self.mnr = int(versions[1])
            self.ptch = int(versions[2])
        else:
            self.mjr, self.mnr, self.ptch = args
        
    @property
    def major(self):
        return self.mjr
    
    @property    
    def minor(self):
        return self.mnr
    
    @property
    def patch(self):
        return self.ptch

    def __str__(self):
        return f"{self.major}.{self.minor}.{self.patch}"
    
    def __repr__(self):
        return f"Version({self.major}, {self.minor}, {self.patch})"
    
    def __eq__(self, other):
        if isinstance(other, Version):
            return self.major == other.major and self.minor == other.minor and self.patch == other.patch
        elif isinstance(other, str):
            v = Version(other)
            return self.major == v.major and self.minor == v.minor and self.patch == v.patch
        else: return False
    
    def __ne__(self, other):
        return not self.__eq__(other)
    
    def __lt__(self, other):
        if isinstance(other, Version):
            return self.major < other.major or self.minor < other.minor or self.patch < other.patch
        elif isinstance(other, str):
            v = Version(other)
            return self.major < v.major or self.minor < v.minor or self.patch < v.patch
        else: return False
        
    def __gt__(self, other):
        if isinstance(other, Version):
            return self.major > other.major or self.minor > other.minor or self.patch > other.patch
        elif isinstance(other, str):
            v = Version(other)
            return self.major > v.major or self.minor > v.minor or self.patch > v.patch
        else: return False

# Tests:

assert Version(1, 2, 3).major == 1
assert Version(1, 2, 3).minor == 2
assert Version(1, 2, 3).patch == 3
assert Version("1.2.3").major == 1
assert Version("1.2.3").minor == 2
assert Version("1.2.3").patch == 3
assert Version("10.2.304").major == 10
assert Version("10.2.304").minor == 2
assert Version("10.2.304").patch == 304
assert str(Version(1, 2, 3)) == "1.2.3"
assert repr(Version(1, 2, 3)) == "Version(1, 2, 3)"
assert Version(1, 2, 3) == Version(1, 2, 3)
assert Version(1, 2, 3) == "1.2.3"
assert Version(1, 2, 3) != Version(1, 2, 4)
assert Version(1, 2, 3) != "1.2.4"
assert Version(1, 2, 3) < Version(2, 0, 0)
assert Version(1, 2, 3) < "2.0.0"
assert Version(1, 2, 3) < Version(1, 3, 0)
assert Version(1, 2, 3) < "1.3.0"
assert Version(1, 2, 3) < Version(1, 2, 4)
assert Version(1, 2, 3) < "1.2.4"
assert Version("1.2.3") < Version("1.12.0")
assert Version("1.2.3") < "1.12.0"
assert Version(1, 2, 3) > Version(0, 9, 0)
assert Version(1, 2, 3) > "0.9.0"
assert Version(1, 2, 3) > Version(1, 1, 0)
assert Version(1, 2, 3) > "1.1.0"
assert Version(1, 2, 3) > Version(1, 2, 2)
assert Version(1, 2, 3) > "1.2.2"
assert Version("1.1.13") > Version("1.1.3")
assert Version("1.1.13") > "1.1.3"

"✅ All OK! +1 point"