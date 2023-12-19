import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class NumberToWordsConverter {
    private static final Map<Integer, String> wrd = new HashMap<>();
    private static final Map<Integer, String> place = new HashMap<>();

    static {
        wrd.put(0, "");
        wrd.put(1, "one ");
        wrd.put(2, "two ");
        wrd.put(3, "three ");
        wrd.put(4, "four ");
        wrd.put(5, "five ");
        wrd.put(6, "six ");
        wrd.put(7, "seven ");
        wrd.put(8, "eight ");
        wrd.put(9, "nine ");
        wrd.put(10, "ten ");
        wrd.put(11, "eleven ");
        wrd.put(12, "twelve ");
        wrd.put(13, "thirteen ");
        wrd.put(14, "fourteen ");
        wrd.put(15, "fifteen ");
        wrd.put(16, "sixteen ");
        wrd.put(17, "seventeen ");
        wrd.put(18, "eighteen ");
        wrd.put(19, "nineteen ");
        wrd.put(20, "twenty ");
        wrd.put(30, "thirty ");
        wrd.put(40, "forty ");
        wrd.put(50, "fifty ");
        wrd.put(60, "sixty ");
        wrd.put(70, "seventy ");
        wrd.put(80, "eighty ");
        wrd.put(90, "ninety ");

        place.put(1, "hundred ");
        place.put(2, "thousand ");
        place.put(3, "million ");
        place.put(4, "billion ");
        place.put(5, "trillion ");
        place.put(6, "quadrillion ");
        place.put(7, "quintillion ");
    }

    private static String[] mainFunc(String x) {
        String[] li = x.split(",");
        return li;
    }

    private static String prt(int num, int length, int lastIndex) {
        boolean value = true;
        StringBuilder st = new StringBuilder();
        int o = num % 10;
        num /= 10;
        int t = num % 10;
        num /= 10;
        int h = num % 10;

        if (num < 20) {
            st.append(wrd.get(num));
            value = !(h == 0 && t == 0 && o == 0);
        } else {
            if (h > 0) {
                st.append(wrd.get(h)).append(place.get(1));
            }
            if ((t * 10 + o) < 20) {
                st.append(wrd.get(t * 10 + o));
            } else {
                if (t > 0) {
                    st.append(wrd.get(t * 10));
                    if (o > 0) {
                        st.append(" ");
                    }
                }
                if (o > 0) {
                    st.append(wrd.get(o));
                }
            }
        }

        if (lastIndex > 1 && value) {
            st.append(place.get(length));
        }

        return st.toString();
    }

    private static String convertToWords(String input) {
        StringBuilder myst = new StringBuilder();
        int num = Integer.parseInt(input);

        if (num < 0) {
            myst.append("Negative ");
            num = Math.abs(num);
        }

        if (num == 0) {
            myst.append("zero");
        }

        if (input.length() > 21) {
            return "Please enter a number smaller than or equal to 21 digits";
        } else {
            System.out.println("Your number is: " + num);

            String[] tempList = mainFunc(input);
            int tempLen = tempList.length;

            for (String i : tempList) {
                myst.append(prt(Integer.parseInt(i), tempLen, tempLen));
                tempLen--;
            }

            return myst.toString().trim();
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        String user_input = scanner.nextLine();
        String words_output = convertToWords(user_input);
        System.out.println("In words: " + words_output);
        scanner.close();
    }
}
