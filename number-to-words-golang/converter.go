package main

import (
	"fmt"
	"strconv"
	"strings"
)

var wrd = map[int]string{
    0:  "",
    1:  "one ",
    2:  "two ",
    3:  "three ",
    4:  "four ",
    5:  "five ",
    6:  "six ",
    7:  "seven ",
    8:  "eight ",
    9:  "nine ",
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
    90: "ninety ",
}

var place = map[int]string{
    1: "hundred ",
    2: "thousand ",
    3: "million ",
    4: "billion ",
    5: "trillion ",
    6: "quadrillion ",
    7: "quintillion ",
}

func main() {
	var userInput string
	fmt.Print("Enter a number: ")
	_, err := fmt.Scan(&userInput)
	if err != nil {
		fmt.Println("Error reading input:", err)
		return
	}

	wordsOutput := convertToWords(userInput)
	fmt.Println("In words:", wordsOutput)
}

func mainFunc(x string) []string {
	return strings.Split(x, ",")
}

func prt(num, length, lastIndex int) string {
	value := true
	var st strings.Builder
	x, o, t, h := num, num%10, 0, 0
	x /= 10
	t = x % 10
	x /= 10
	h = x % 10

	if num < 20 {
		st.WriteString(wrd[num])
		if h == 0 && t == 0 && o == 0 {
			value = false
		}
	} else {
		if h > 0 {
			st.WriteString(wrd[h] + place[1])
		}
		if t*10+o < 20 {
			st.WriteString(wrd[t*10+o])
		} else {
			if t > 0 {
				st.WriteString(wrd[t*10])
				if o > 0 {
					st.WriteString(" ")
				}
			}
			if o > 0 {
				st.WriteString(wrd[o])
			}
		}
	}

	if lastIndex > 1 && value {
		st.WriteString(place[length])
	}

	return st.String()
}

func convertToWords(input string) string {
	var myst strings.Builder
	num, err := strconv.Atoi(input)
	if err != nil {
		return "Invalid input"
	}

	if num < 0 {
		myst.WriteString("Negative ")
		num = -num
	}

	if num == 0 {
		myst.WriteString("zero")
	}

	if len(input) > 21 {
		return "Please enter a number smaller than or equal to 21 digits"
	} else {
		fmt.Println("Your number is:", num)

		tempList := mainFunc(input)
		tempLen := len(tempList)

		for _, i := range tempList {
			convNum, _ := strconv.Atoi(i)
			myst.WriteString(prt(convNum, tempLen, tempLen))
			tempLen--
		}

		return myst.String()
	}
}
