// your code here
const input = document.querySelector(".input");
input.value = "";
const buttons = document.querySelector(".action-grid");
const actionBtns = Array.from(document.querySelectorAll(".action-btn"));
const operations = Array.from(document.querySelectorAll(".orange"))
const history = document.querySelector(".calculation-list");
const clearBtn = document.querySelector(".clear");
let clickedOps;
let expression = "";
letres = 0;
const max = document.querySelector(".max");
const calculator = document.querySelector(".wrapper");
// let expressionForHistory = "";

buttons.addEventListener("click", (event) => {
    const el = event.target;

    if (clickedOps !== undefined)
        clickedOps.style.border = "none";
    // console.log(el);
    if (el.classList.contains("orange")) {
        if (input.value === "") {
            return;
        }
        if (el !== operations[4]){
            el.style.border = "1px solid black";
        }

        if (el === operations[0]) {
            expression += input.value;
            expression += "/";

        }
        else if (el == operations[1]) {
            expression += input.value;
            expression += "*";
        }
        else if (el === operations[2]) {
            expression += input.value;
            expression += "-";
        }
        else if (el === operations[3]) {
            expression += input.value;
            expression += "+";
        }
        else if (el === operations[4]) {
            expression += input.value;
            console.log(expression);
            input.value = eval(expression).toString();
            const li = document.createElement("li");
            li.textContent = `${expression} = ${input.value}`;
            history.appendChild(li);
            expression = "";
            // expression = input.value.toString();
        }

        clickedOps = el;
        
        if (el !== operations[4]) {
            input.value = "";
        }


    }
    else if (el.classList.contains("action-btn")){
        if (el === actionBtns[0]) {
            input.value  = "";
        }
        else if (el === actionBtns[1]) {
            if (input.value !== "") {
                const li = document.createElement("li");
                res = Math.sqrt(Number(input.value));
                li.innerHTML = `&#8730;${input.value} = ${res}`;

                history.appendChild(li);
                input.value = res.toString();
            }
        }
        else if (el === actionBtns[2]) {
            if (input.value !== "") {
                const li = document.createElement("li");
                res = Math.pow(Number(input.value), 2);
                li.innerHTML = `${input.value}<sup>2</sup> = ${res.toString()}`;

                history.appendChild(li);
                input.value = res.toString();
            }
        }
    }
    else {
        input.value += el.textContent;
        // if (el.textContent === ".") 
        // expression += input.value;
    }
    
});

clearBtn.addEventListener("click", (e) => {
    while (history.firstChild) {
        history.removeChild(history.firstChild);
    }
});


max.addEventListener("click", (e) => {
    calculator.style.width = "468px";
    calculator.style.height = "644px";

})



console.log();