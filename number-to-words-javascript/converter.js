let wrd = {
    0: "",
    1: "one ",
    2: "two ",
    3: "three ",
    4: "four ",
    5: "five ",
    6: "six ",
    7: "seven ",
    8: "eight ",
    9: "nine ",
    10: "ten ",
    11: "eleven ",
    12: "twelve ",
    13: "thirteen ",
    14: "fourteen ",
    15: "fifteen ",
    16: "sixteen ",
    17: "seventeen ",
    18: "eighteen ",
    19: "nineteen ",
    20: "twenty ",
    30: "thirty ",
    40: "forty ",
    50: "fifty ",
    60: "sixty ",
    70: "seventy ",
    80: "eighty ",
    90: "ninety "
};

let place = {
    1: "hundred ",
    2: "thousand ",
    3: "million ",
    4: "billion ",
    5: "trillion ",
    6: "quadrillion ",
    7: "quintillion "
};

function main(x) {
    let li = x.split(',').reverse(); // Reverse the array for correct reading order
    return li;
}

function prt(num, length, last_index) {
    let value = true;
    let st = "";
    let x = num;
    let o = x % 10;
    x = Math.floor(x / 10);
    let t = x % 10;
    x = Math.floor(x / 10);
    let h = x % 10;

    if (num < 20) {
        st = wrd[num];
        if (h == 0 && t == 0 && o == 0) {
            value = false;
        }
    } else {
        if (h > 0) {
            st += wrd[h] + place[1];
        }

        if (t * 10 + o < 20) {
            st += wrd[t * 10 + o];
        } else {
            if (t > 0) {
                st += wrd[t * 10];
                if (o > 0) {
                    st += "-";
                }
            }
            if (o > 0) {
                st += wrd[o];
            }
        }
    }

    if (last_index > 1 && value) {
        st += place[length];
    }

    return st;
}

function convertToWords(input) {
    let myst = "";
    let num = parseInt(input);

    if (num < 0) {
        myst = "Negative ";
        input = Math.abs(num).toString();
    }

    if (num === 0) {
        myst = "zero";
    }

    if (input.length > 21) {
        return 'Please enter a number smaller than or equal to 21 digits';
    } else {
        let temp_list = main(input);
        let temp_len = temp_list.length;

        for (let i of temp_list) {
            myst += prt(parseInt(i), temp_len, temp_len);
            temp_len--;
        }

        return myst.trim();
    }
}

// Example usage
let userInput = prompt('Enter a number:');
let numberOutput = parseInt(userInput).toLocaleString();
let wordsOutput = convertToWords(userInput);

console.log("Your number is:", numberOutput);
console.log("In words:", wordsOutput);
