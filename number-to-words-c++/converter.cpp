#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

std::unordered_map<int, std::string> wrd = {
    {0, ""}, 
    {1, "one "}, 
    {2, "two "}, 
    {3, "three "}, 
    {4, "four "}, 
    {5, "five "},
    {6, "six "}, 
    {7, "seven "}, 
    {8, "eight "}, 
    {9, "nine "}, 
    {10, "ten "},
    {11, "eleven "}, 
    {12, "twelve "}, 
    {13, "thirteen "}, 
    {14, "fourteen "}, 
    {15, "fifteen "},
    {16, "sixteen "}, 
    {17, "seventeen "}, 
    {18, "eighteen "}, 
    {19, "nineteen "},
    {20, "twenty "}, 
    {30, "thirty "}, 
    {40, "forty "}, 
    {50, "fifty "}, 
    {60, "sixty "},
    {70, "seventy "}, 
    {80, "eighty "}, 
    {90, "ninety "}
};

std::unordered_map<int, std::string> place = {
    {1, "hundred "}, 
    {2, "thousand "}, 
    {3, "million "}, 
    {4, "billion "},
    {5, "trillion "}, 
    {6, "quadrillion "}, 
    {7, "quintillion "}
};

std::vector<std::string> splitInput(const std::string& input) {
    std::string temp = input;
    int len = temp.size();
    int count = 0;

    for (int i = len - 1; i >= 0; i--) {
        count++;
        if (count == 3 && i != 0) {
            temp.insert(i, ",");
            count = 0;
        }
    }

    std::istringstream iss(temp);
    std::vector<std::string> splitNumbers;
    std::string token;

    while (std::getline(iss, token, ',')) {
        splitNumbers.push_back(token);
    }

    return splitNumbers;
}

std::string prt(int num, int length, int last_index) {
    bool value = true;
    std::string st;
    int o = num % 10;
    num /= 10;
    int t = num % 10;
    num /= 10;
    int h = num % 10;

    if (num < 20) {
        st = wrd[num];
        value = !(h == 0 && t == 0 && o == 0);
    } else {
        if (h > 0) {
            st += wrd[h] + place[1];
        }
        if ((t * 10 + o) < 20) {
            st += wrd[t * 10 + o];
        } else {
            if (t > 0) {
                st += wrd[t * 10];
                if (o > 0) {
                    st += " ";
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

void convert_to_words(const std::string& input) {
    std::string myst;
    int num = std::stoi(input);

    if (num < 0) {
        myst = "Negative ";
        num = std::abs(num);
    }

    if (num == 0) {
        myst = "zero";
    }

    if (input.length() > 21) {
        std::cout << "Please enter a number smaller than or equal to 21 digits" << std::endl;
    } else {
        std::cout << "Your number is: " << std::stoi(input) << std::endl;

        std::vector<std::string> temp_list = splitInput(input);
        int temp_len = temp_list.size();

        for (const std::string& i : temp_list) {
            myst += prt(std::stoi(i), temp_len, temp_len);
            temp_len--;
        }

        std::cout << "In words: " << myst << std::endl;
    }
}

int main() {
    std::string input;
    std::cout << "Enter a number: ";
    std::cin >> input;
    convert_to_words(input);
    return 0;
}
