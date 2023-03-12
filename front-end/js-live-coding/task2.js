// Мартин Христов => Martin Hristov
// Янислав Тодоров => Yanislav Todorov
// Цанислав Гатев => Tsanislav Gatev
// Живко Иванов => Zhivko Ivanov
// Ния Пеева => Niya Peeva


const inputs = [
  "Мартин Христов",
  "Янислав Тодоров",
  "Цанислав Гатев",
  "Живко Иванов",
  "Ния Пеева",
];

const mapping = {
  "м": "m",
  "а": "a",
  "р": "r",
  "т": "t",
  "и": "i",
  "н": "n",
  "х": "h",
  "и": "i",
  "с": "s",
  "т": "t",
  "о": "o",
  "я": "ya",
  "н": "n",
  "и": "i",
  "с": "s",
  "л": "l",
  "в": "v",
  "o": "o",
  "д": "d",
};

const translate = (name) => {
  const nameAsArray = name.split("") // Мартин  => ["M", "a", "р", "т", "и", "н"]

  const capitalize = (str) => {
    return str[0].toUpperCase() + str.slice(1, str.length); // lorem => (str[0].toUpperCase() -> l => L)
  };

  const mappingResult = nameAsArray.map(letter => {
    const maapped = mapping[letter.toLowerCase()];

    if (!maapped) {
      return letter;
    }

    const isCapital = letter !== letter.toLowerCase();

    if (isCapital) {
      return capitalize(mapping[letter.toLowerCase()]);
    }

    return mapping[letter.toLowerCase()];
  });

  return mappingResult.join("");
};

console.log(translate(inputs[1]));