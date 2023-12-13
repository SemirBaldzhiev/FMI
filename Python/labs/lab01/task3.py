def merge(d1, d2):
    return {**d1, **d2}

# Tests:

assert merge({"name": "Pesho", "year": 1999}, {"groups": ["A", "B"]}) == {"name": "Pesho", "year": 1999, "groups": ["A", "B"]}
assert merge({}, {}) == {}

"✅ All OK! +0.25 points"