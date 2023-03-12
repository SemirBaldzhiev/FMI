const isPalindrome = str => {
    const len = str.length;
    for (let i = 0; i < len / 2; ++i) {
        if (str[i] !== str[len - i - 1]) {
            return false;
        }
    }

    return true;
}

const palindromes = arr => {
    let res = [];
    arr.forEach(str => {
        if (isPalindrome(str)) {
            res.push(str);
        }
    });

    return res;
}

const words = ["abccba", "lalala", "something", "123321", "debel lebed"];
console.log(palindromes(words));



