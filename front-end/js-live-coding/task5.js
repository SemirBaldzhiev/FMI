const input = [
  () => console.log("test"),
  1,
  "2",
  "3",
  "4",
  5.00,
  {
    name: "Martin"
  },
  false,
  true,
  "false",
  [1,2,3,4],
];

const counterMap = {
  "Strings": 0,
  "Numbers": 0,
  "Booleans": 0,
  "Objects": 0,
  "Functions": 0,
  "Arrays": 0,
}

input.forEach(item => {
  if (typeof item === "function") { // item.call
    counterMap["Functions"] += 1;
  }

  if (typeof item === "number") { 
    counterMap["Numbers"] += 1;
  }

  if (typeof item === "boolean") { // item === Boolean(item)
    counterMap["Booleans"] += 1;
  }

  if (typeof item === "object") {
    if (Array.isArray(item)) {
      counterMap["Arrays"] += 1;  
    } else {
      counterMap["Objects"] += 1;
    }

  }

  if (typeof item === "string") {
    counterMap["Strings"] += 1;
  }
});

console.log(counterMap)