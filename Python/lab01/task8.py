import math
def find_shortest_and_longest_words(words, letter):
    max = -math.inf
    min = math.inf
    shortest = ""
    longest = ""
    
    for word in words:
        if word[0] == letter:
            curr_len = len(word)
            if curr_len > max:
                max = curr_len
                longest = word
            if curr_len < min:
                min = curr_len
                shortest = word
                
    return shortest, longest
# Tests

assert find_shortest_and_longest_words(["abracadabra", "banana", "kugelschreiber", "ant", "almost", "thisshouldbeaverylongword"], "a") == ("ant", "abracadabra")
assert find_shortest_and_longest_words(["abracadabra", "banana", "kugelschreiber", "ant", "almost", "thisshouldbeaverylongword"], "b") == ("banana", "banana")

"✅ All OK! +0.5 points"