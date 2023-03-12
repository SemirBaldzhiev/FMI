const input = "Anna Dosewa Asenowa, Iwo Peew Peew";
const names = input.split(", ");
const first = names[0];
const second = names[1];

let firstCounter = 0;
let secondCounter = 0;

const firstMapped = first.split("").map(letter => letter.charCodeAt(0));
const secondMapped = second.split("").map(letter => letter.charCodeAt(0));

firstMapped.forEach(code => firstCounter += code); 
secondMapped.forEach(code => secondCounter += code);

console.log(firstCounter > secondCounter ? first : second);
