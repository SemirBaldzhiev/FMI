const input = "Do ex excepteur qui in. Eiusmod eu enim excepteur anim in nulla enim aliquip voluptate. Excepteur id consequat amet labore adipisicing occaecat ipsum mollit esse ut sunt do velit. Anim esse veniam ea cillum minim dolor exercitation adipisicing exercitation. Velit esse ad minim et ad aliqua. Elit consectetur id reprehenderit proident cillum ipsum sunt sint. Id dolor aute sit nisi excepteur ullamco incididunt esse occaecat culpa elit nisi.";

const counterMap = {
  // D: 1
  // a: 13
};

input.split("").forEach(el => {
  const lower = el.toLowerCase();

  if (!/[a-z]/.test(lower)) {
    return;
  }

  if (!counterMap[lower]) { // counterMap["D"] 
    counterMap[lower] = 1;
  } else {
    counterMap[lower] += 1;
  }
});

Object.keys(counterMap).forEach(letter => { // Object keys / Object value
  console.log(`${letter}: ${counterMap[letter]}`);
});

