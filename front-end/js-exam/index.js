const sumArrays = (arr1, arr2) => {
    const flatArr1 = [];
    const flatArr2 = [];
    const onlyNums = [];
    flatten(arr1, flatArr1);
    flatten(arr2, flatArr2);
    if (doesntContainsNums(flatArr1) && doesntContainsNums(flatArr2)) {
      return 'No number type found in input arrays';
    }
    if (constainsOnlyNums(flatArr1) && constainsOnlyNums(flatArr2)) {
      const filteredArr = flatArr1.filter(v => flatArr2.includes(v) && v % 3 === 0)
      return filteredArr.reduce((acc, cur) => acc + cur, 0)
    } else {
      getOnlyNumbers(flatArr1, onlyNums);
      getOnlyNumbers(flatArr2, onlyNums);
      return `Min number found is ${Math.min(...onlyNums)}`;
    }
};

const constainsOnlyNums = arr => {
  return arr.every(el => typeof el === 'number');
}

const getOnlyNumbers = (arr, res) => {
  arr.forEach(el => {
    if (typeof el === 'number'){
      res.push(el);
    }
  });
}

const doesntContainsNums = (arr) => {
  return arr.every(el => typeof el !== 'number');
}
const flatten = (arr, result) => {
  arr.forEach(el => {
    if (Array.isArray(el)) {
      flatten(el, result);
    } else {
      result.push(el);
    }
  })
};

// console.log(sumArrays([1, 2, 3, 4, 5, 6, 7, 8, 9], [7, 8, 6, 10, 11, 12, 9])); // 15
// console.log(sumArrays([1, 2, [3, [4, [5, [6]]]]], [4, [[[[[[6]]]]]]])); // 6
// console.log(sumArrays([1, 2, 3, () => {}], [3, 4])); // Min number found is 1
// console.log(sumArrays([() => {}], ["1"])); // No number type found in input arrays
// console.log(sumArrays([() => {}], [{}])); // No number type found in input arrays

const input = [
  { name: "Martin", mark: 4, course: "SI" },
  { name: "Elena", mark: 6, course: "IS" },
  { name: "Tsani", mark: 5, course: "IS" },
  { name: "Niya", mark: 2.9, course: "IS" },
  { name: "Ivo", mark: 2.5, course: "KN" }
];


const getTopStudents = students => {
  return students.filter(s => s.mark >= 5.5);
};
const getLowStudents = students => {
  return students.filter(s => s.mark < 3);
};
const orderStudents = (students, criteria) => {
  
  let newStudents = [];
  students.forEach(s => {
    const st = {};
    st.name = s.name;
    if (s.mark < 3) {
      st.mark = 2;
    } else {
      st.mark = Math.ceil(s.mark);
    }
    st.course = s.course;
    newStudents.push(st);
  })

  if (typeof criteria !== 'undefined' && typeof criteria.course !== 'undefined') {
    newStudents = newStudents.filter(s => s.course === criteria.course)   
  }
  const sorted = [...newStudents.sort((a, b) => {
    if (typeof criteria === 'undefined') {
      return a.mark - b.mark;
    }

    if (typeof criteria !== 'undefined' && typeof criteria.type === 'undefined') {
      return a.mark - b.mark;
    }

    if (typeof criteria !== 'undefined' && typeof criteria.type !== 'undefined') {
      if (criteria.type === 'ascending'){
        return a.mark - b.mark;
      }

      if (criteria.type === 'descending') {
        return b.mark - a.mark;
      }
    }

  })];

  return sorted;
};

// console.log('Top: ', getTopStudents(input));
// console.log('Low: ', getLowStudents(input));
// console.log('ascending all: ', orderStudents([...input]));
// console.log('descending all: ', orderStudents([...input], { type: "descending" }));
// console.log('ascending IS: ', orderStudents([...input], { course: "IS"}));
// console.log('descending IS: ', orderStudents([...input], { type: "descending", course: "IS" }));
// console.log('ascending: IS', orderStudents([...input], { type: "ascending", course: "IS" }));

export { sumArrays, getTopStudents, getLowStudents, orderStudents };
