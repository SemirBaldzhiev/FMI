def unique_chars_count(s):
    return len(set(s))

# Tests:

assert unique_chars_count("abcdef") == 6
assert unique_chars_count("aabbcc") == 3
assert unique_chars_count("abcabc") == 3
assert unique_chars_count("aaaaaa") == 1
assert unique_chars_count("") == 0

"✅ All OK! +0.25 points"