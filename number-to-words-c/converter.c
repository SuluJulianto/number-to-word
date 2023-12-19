#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *wrd[] = {
    "",
    "one ",
    "two ",
    "three ",
    "four ",
    "five ",
    "six ",
    "seven ",
    "eight ",
    "nine ",
    "ten ",
    "eleven ",
    "twelve ",
    "thirteen ",
    "fourteen ",
    "fifteen ",
    "sixteen ",
    "seventeen ",
    "eighteen ",
    "nineteen ",
    "twenty ",
    "thirty ",
    "forty ",
    "fifty ",
    "sixty ",
    "seventy ",
    "eighty ",
    "ninety "
};

char *place[] = {
    "",
    "hundred ",
    "thousand ",
    "million ",
    "billion ",
    "trillion ",
    "quadrillion ",
    "quintillion "
};


typedef struct {
    char **list;
    int count;
} ArrayResult;

ArrayResult *main_func(char *x) {
    int len = strlen(x);
    int count = 0, i;
    char *temp = (char *)malloc(len + 1);
    strcpy(temp, x);

    for (i = len - 1; i >= 0; i--) {
        count++;
        if (count == 3 && i != 0) {
            temp[i] = ',';
            count = 0;
        }
    }
    char **li = (char **)malloc(sizeof(char *) * len);
    char *ptr = strtok(temp, ",");
    count = 0;

    while (ptr != NULL) {
        li[count] = ptr;
        count++;
        ptr = strtok(NULL, ",");
    }

    free(temp);

    ArrayResult *result = (ArrayResult *)malloc(sizeof(ArrayResult));
    result->list = li;
    result->count = count;
    return result;
}

char *prt(int num, int length, int last_index) {
    int value = 1;
    char *st = (char *)malloc(sizeof(char) * 100);
    int x = num, o, t, h;
    o = x % 10;
    x /= 10;
    t = x % 10;
    x /= 10;
    h = x % 10;

    if (num < 20) {
        strcpy(st, wrd[num]);
        value = (h == 0 && t == 0 && o == 0) ? 0 : 1;
    } else {
        if (h > 0) {
            strcpy(st, wrd[h]);
            strcat(st, place[1]);
        }
        if ((t * 10 + o) < 20) {
            strcat(st, wrd[t * 10 + o]);
        } else {
            if (t > 0) {
                strcat(st, wrd[t * 10]);
                if (o > 0) {
                    strcat(st, " ");
                }
            }
            if (o > 0) {
                strcat(st, wrd[o]);
            }
        }
    }

    if (last_index > 1 && value) {
        strcat(st, place[length]);
    }

    return st;
}

void convert_to_words(char *input) {
    char *myst = (char *)malloc(sizeof(char) * 100);
    int num = atoi(input);

    if (num < 0) {
        strcpy(myst, "Negative ");
        num = abs(num);
    }

    if (num == 0) {
        strcpy(myst, "zero");
    }

    if (strlen(input) > 21) {
        printf("Please enter a number smaller than or equal to 21 digits\n");
    } else {
        printf("Your number is: %s\n", input);

        ArrayResult *temp_result = main_func(input);
        char **temp_list = temp_result->list;
        int temp_len = temp_result->count;

        for (int i = 0; i < temp_len; i++) {
            strcat(myst, prt(atoi(temp_list[i]), temp_len, temp_len));
            temp_len--;
        }

        printf("In words: %s\n", myst);
    }

    free(myst);
}

int main() {
    char input[50];
    printf("Enter a number: ");
    scanf("%s", input);
    convert_to_words(input);
    return 0;
}
