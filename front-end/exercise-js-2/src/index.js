const countryList = document.getElementById('countryList');
const regionsList = document.querySelector('select');
const searchBtn = document.querySelector('.filter-btn');

let countries = [];

async function addToList() {

    countries.map(country => {
        const li = document.createElement('li');
        li.classList.add("country");
        const innerLiHtml  = `<img
        class="country-image"
        alt="Belarus flag"
        src="${country.flags.svg}"
      />
      <div class="country-title">${country.name.official}</div>
      <a class="country-btn" href="../detail.html">More information</a>`;

      li.innerHTML += innerLiHtml;
      countryList.appendChild(li);
    });
}

async function fetchCountries() {
    const response = await fetch('https://restcountries.com/v3.1/all');
    countries = await response.json();

    console.log(countries[0]);
    addToList();
} 
await fetchCountries();

const moreInfoLink = document.querySelector('.country-btn');

moreInfoLink.addEventListener('click', (e) => {
    const countryName = e.parent.querySelector('.country-title').textContent;
    const country = countries.filter(country.name.official === countryName);

    console.log(country);

})


// async function filterByRegion() {
//     const region = regionsList.options[regionsList.selectedIndex].value;
    
//     const regionUrl = `https://restcountries.com/v3.1/region/${region}`;

//     const res = await fetch(regionUrl);
//     const filteredCountries = res.json();
//     console.log(filteredCountries);
//     countryList.innerHTML = '';
//     addToList(filteredCountries);
//     console.log(region);
// }


// searchBtn.addEventListener('click', (e) => {
//     filterByRegion();
// });






