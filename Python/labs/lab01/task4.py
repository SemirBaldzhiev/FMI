import math
def digits_count(n):
    if n == 0:
        return 1
    return int(math.log10(n))+1

# Tests:

assert digits_count(0) == 1
assert digits_count(1) == 1
assert digits_count(9) == 1
assert digits_count(10) == 2
assert digits_count(666) == 3
assert digits_count(1234) == 4
assert digits_count(9876543210) == 10
assert digits_count(31415926535897932384626433832795028841971693993751058209749445923078164062862089986280) == 86

"✅ All OK! +0.25 points"