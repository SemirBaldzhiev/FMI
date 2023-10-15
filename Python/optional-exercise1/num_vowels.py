# volews - a, e, i, o, u
def number_of_vowels(text):
    text = text.lower()
    volews = ['a', 'e', 'i', 'o', 'u']
    cnt = 0
    for c in text:
        if c in volews:
            cnt += 1
    return cnt


print(number_of_vowels("grrrrgh!") == 0)
print(number_of_vowels("The quick brown fox jumps over the lazy dog.") == 11)
print(number_of_vowels("MONTHY PYTHON") == 2)