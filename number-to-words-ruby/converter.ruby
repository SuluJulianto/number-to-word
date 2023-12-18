$wrd = {
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
}

$place = {
  1 => "hundred ",
  2 => "thousand ",
  3 => "million ",
  4 => "billion ",
  5 => "trillion ",
  6 => "quadrillion ",
  7 => "quintillion "
}

def main(x)
  li = x.reverse.scan(/.{1,3}/).reverse.map(&:reverse)
end

def prt(num, length, last_index)
  value = true
  st = ""
  x = num
  o = x % 10
  x /= 10
  t = x % 10
  x /= 10
  h = x % 10

  if num < 20
    st = $wrd[num]
    value = false if h == 0 && t == 0 && o == 0
  else
    st += $wrd[h] + $place[1] if h > 0
    if (t * 10 + o) < 20
      st += $wrd[t * 10 + o]
    else
      if t > 0
        st += $wrd[t * 10]
        st += " " if o > 0
      end
      st += $wrd[o] if o > 0
    end
  end

  st += $place[length] if last_index > 1 && value
  st
end

def convert_to_words(input)
  myst = ""
  num = input.to_i

  if num < 0
    myst = "Negative "
    input = num.abs.to_s
  end

  if num == 0
    myst = "zero"
  end

  if input.length > 21
    puts 'Please enter a number smaller than or equal to 21 digits'
  else
    number_output = input.reverse.gsub(/(\d{3})(?=\d)/, '\\1,').reverse
    puts "Your number is: #{number_output}"

    temp_list = main(input)
    temp_len = temp_list.length

    temp_list.each do |i|
      myst += prt(i.to_i, temp_len, temp_len)
      temp_len -= 1
    end

    puts "In words: #{myst.strip}"
  end
end

print 'Enter a number: '
user_input = gets.chomp
convert_to_words(user_input)
