BAD_WORDS = [
    "fuck",
    "shit",
    "bullshit",
    "bastard",
    "bitch",
    "whore",
    "damn",
]


def censored(text):
    words = text.split()
    
    for i in range(len(words)):
        if words[i].lower() in BAD_WORDS:
            words[i] = len(words[i])*'*'
    return ' '.join(words)


# Tests:

assert censored("fuck this bitch") == "**** this *****"
assert censored("this line should not be censored at all") == "this line should not be censored at all"
assert censored("This task is UTTER BULLshit") == "This task is UTTER ********", "be careful with the case!"
assert censored("") == ""

"✅ All OK! +0.75 points"