const input = [
  {
    name: "Martin",
    lastname: "Hristov",
    fn: 61733,
    grade: 3
  },

  {
    name: "Tsanislav",
    lastname: "Hristov",
    fn: 62547,
    grade: 2.9
  },

  {
    name: "Ivo",
    lastname: "Georgiev",
    fn: 68554,
    grade: 5.6
  },

  {
    name: "Niya",
    lastname: "Peeva",
    fn: 71585,
    grade: 5.5
  }
];


const filterTopStudents = (students) => {
  const topStudents = students.filter(student => {
    return student.grade >= 5.5;
  });

  return topStudents.map(student => {
    // Niya Peeva, fn: 71585
    return `${student.name} ${student.lastname}, fn: ${student.fn}`;
  }).join(", ");
}

console.log(filterTopStudents(input));

const filterPassedStudents = (students) => {
  return students.map(student => {
    return {
      ...student,
      grade: student.grade < 3 ? 2 : student.grade
    }
  });
}

console.log(filterPassedStudents(input))