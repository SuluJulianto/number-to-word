<?php
$wrd = array(
    0 => "",
    1 => "one ",
    2 => "two ",
    3 => "three ",
    4 => "four ",
    5 => "five ",
    6 => "six ",
    7 => "seven ",
    8 => "eight ",
    9 => "nine ",
    10 => "ten ",
    11 => "eleven ",
    12 => "twelve ",
    13 => "thirteen ",
    14 => "fourteen ",
    15 => "fifteen ",
    16 => "sixteen ",
    17 => "seventeen ",
    18 => "eighteen ",
    19 => "nineteen ",
    20 => "twenty ",
    30 => "thirty ",
    40 => "forty ",
    50 => "fifty ",
    60 => "sixty ",
    70 => "seventy ",
    80 => "eighty ",
    90 => "ninety "
);

$place = array(
    1 => "hundred ",
    2 => "thousand ",
    3 => "million ",
    4 => "billion ",
    5 => "trillion ",
    6 => "quadrillion ",
    7 => "quintillion "
);

function main($x) {
    $li = strrev(preg_replace("/(\d{3})(?=\d)/", "$1,", strrev($x)));
    return explode(',', $li);
}

function prt($num, $length, $last_index) {
    $value = true;
    $st = "";
    $x = $num;
    $o = $x % 10;
    $x = intval($x / 10);
    $t = $x % 10;
    $x = intval($x / 10);
    $h = $x % 10;

    if ($num < 20) {
        $st = $GLOBALS['wrd'][$num];
        $value = $h == 0 && $t == 0 && $o == 0 ? false : true;
    } else {
        if ($h > 0) {
            $st .= $GLOBALS['wrd'][$h] . $GLOBALS['place'][1];
        }
        if (($t * 10 + $o) < 20) {
            $st .= $GLOBALS['wrd'][$t * 10 + $o];
        } else {
            if ($t > 0) {
                $st .= $GLOBALS['wrd'][$t * 10];
                if ($o > 0) {
                    $st .= " ";
                }
            }
            if ($o > 0) {
                $st .= $GLOBALS['wrd'][$o];
            }
        }
    }

    if ($last_index > 1 && $value) {
        $st .= $GLOBALS['place'][$length];
    }

    return $st;
}

function convert_to_words($input) {
    $myst = "";
    $num = intval($input);

    if ($num < 0) {
        $myst = "Negative ";
        $input = abs($num);
    }

    if ($num == 0) {
        $myst = "zero";
    }

    if (strlen($input) > 21) {
        return 'Please enter a number smaller than or equal to 21 digits';
    } else {
        echo "Your number is: " . number_format($input) . "\n";

        $temp_list = main($input);
        $temp_len = count($temp_list);

        foreach ($temp_list as $i) {
            $myst .= prt(intval($i), $temp_len, $temp_len);
            $temp_len--;
        }

        echo "In words: " . trim($myst) . "\n";
    }
}

echo 'Enter a number: ';
$user_input = readline();
convert_to_words($user_input);
?>
