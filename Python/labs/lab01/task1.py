def extract_date_components(date_string):
    return tuple(map(int, date_string.split('-')))


# Tests:

assert extract_date_components('1970-01-01') == (1970, 1, 1)
assert extract_date_components('2023-10-22') == (2023, 10, 22)
assert extract_date_components('0000-12-25') == (0, 12, 25)
assert extract_date_components('2009-02-29') == (2009, 2, 29), "no one said it should be a valid date"

"✅ All OK! +0.25 points"