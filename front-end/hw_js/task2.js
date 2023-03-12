class Cat {
    constructor(name, age, breed) {
        this.name = name;
        this.age = age;
        this.breed = breed;
    }
}

function sortCats(cats, constraint) {
    if (constraint === "name") {
        return cats.sort((a, b) => {
            return a.name.localeCompare(b.name);
        });
    }
    else if (constraint === "age") {
        return cats.sort((a, b) => {
            return a.age - b.age;
        });
    }
    else if (constraint === "bread") {
        return cats.sort((a, b) => {
            return a.breed.length - b.breed.length;
        });
    }
    else if (constraint === "all") {
        return cats.sort((a, b) => {
            console.log(a.name);
            const num1 = a.name.length + a.breed.length + a.age;
            const num2 = b.name.length + b.breed.length + b.age;
        
            return num1 - num2;
        });
    }

    return cats;
} 


const cats = [{"name": "Tina", "breed" : "Maine Coon", "age" : 2}, {"name": "Annie", "breed" : "Maine Coon", "age" : 7}, {"name": "Polly", "breed" : "Brittish shorthair", "age" : 3}];
const constraint = "age";

const sorted = sortCats(cats, constraint);

console.log(sorted);


