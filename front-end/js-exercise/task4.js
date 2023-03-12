const input = [[[[[[[[[[1]]]]]]]]]];
const result = [];

const flatten = arr => {
  arr.forEach(el => {
    if (Array.isArray(el)) {
      flatten(el)
    } else {
      result.push(el);
    }
  })
};

flatten(input);

console.log(result);