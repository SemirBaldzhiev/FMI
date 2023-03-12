class Person {

    constructor(name, age, gender) {
        this.name = name;
        this.age = age;
        this.gender = gender;
    }

    showPersonInfo() {
        console.log(`name: ${this.name}`);
        console.log(`age: ${this.age}`);
        console.log(`gender: ${this.gender}`);
    }
}

class Student extends Person{
    constructor(name, age, gender, grade) {
        super(name, age, gender);
        this.grade = grade;
    }

    showStudentInfo() {
        super.showPersonInfo();
        console.log(`grade: ${this.grade}`);
    }
}

class Employee extends Person {
    constructor(name, age, gender, daySalary) {
        super(name, age, gender);
        this.daySalary = daySalary;
    }

    showEmployeeInfo() {
        super.showPersonInfo();
        console.log(`daySalary: ${this.daySalary}`);
    }

    calculateOvertime(hours) {
        if (this.age < 18) {
            return 0;
        }

        return hours * this.daySalary / 8 * 1.5;
    }
}
// demo
let persons = [];
const ivan = new Person('Ivan', 24, "male");
const drago = new Employee("Drago", 23, 'male', 50);
const pencho = new Student("Pencho", 23, 'male', 253);
const gosho = new Person('Gosho', 24, 'male');
const dimitur = new Employee("Mitko", 17, 'male', 50);
const penko = new Student("Penko", 23, 'male', 253);

persons.push(ivan);
persons.push(drago);
persons.push(pencho);
persons.push(gosho);
persons.push(dimitur);
persons.push(penko);

persons.forEach(p => {
    if (p instanceof Person) {
        p.showPersonInfo();
    }
    else if (p instanceof Student) {
        p.showStudentInfo();
    }
    else if (p instanceof Employee) {
        p.showEmployeeInfo();
    }
});

persons.forEach(p => {
    if (p instanceof Employee) {
        console.log(`Overtime bonus: ${p.calculateOvertime(2)}`);
    }
});





