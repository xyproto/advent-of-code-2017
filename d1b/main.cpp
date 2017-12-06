#include <iostream>
#include <stdlib.h>

using namespace std;

using sum_t = uint64_t; // int; // unsigned long long;

// sum_digits sums the digits in the given std::string and returns an integer of type sum_t
sum_t sum_digits(std::string digits) {
    sum_t total = 0;
    for (const auto &digit : digits) {
        total += digit - '0';
        cout << "sum this far: " << total << endl;
    }
    return total;
}

// return the last char
// returns ' ' if given an empty string
char last(std::string digits) {
    auto dl = digits.length();
    if (dl < 1) {
        return ' ';
    }
    return digits.at(dl - 1);
}

// must deal with signed ints for the < 0 check to work
// returns an unsigned int
// is not really clamping, since i is wrapped around instead of clamped
size_t clamp(int64_t i, size_t length) {
    int64_t signed_length = (int64_t)length; // used for dealing with "i" below
    while (i < 0) {
        i += signed_length;
    }
    while (i >= signed_length) {
        i -= signed_length;
    }
    return i;
}

// sum_coupled_digits returns a sum of the digits that are equal to the +offset one
// has clamping and wraparound, so an offset of 1 or 100 will still work, regardless of
// the length of the given string of digits
sum_t sum_coupled_digits(std::string digits, const int64_t offset) {
    // a list of digit couples (neighbours, if offset is 1), as std::string
    auto digit_couples = ""s;
    char digit, other_digit;
    for (size_t i=0; i < digits.length(); i++) {
        digit = digits.at(i);
        // clamp must accept signed ints, because "i - offset" may be signed
        other_digit = digits.at(clamp(i - offset, digits.length()));
        if (digit == other_digit) {
            digit_couples += digit;
        }
    }
    return sum_digits(digit_couples);
}

sum_t sum_halfway_digits(std::string digits) {
    const int64_t offset = digits.length() / 2;
    return sum_coupled_digits(digits, offset);
}

void equal(sum_t a, sum_t b) {
    if (a == b) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        exit(EXIT_FAILURE);
    }
}

int main() {
    equal(clamp(0, 1), 0);
    equal(clamp(1, 1), 0);

    equal(clamp(0, 2), 0);
    equal(clamp(1, 2), 1);
    equal(clamp(2, 2), 0);

    equal(clamp(0, 3), 0);
    equal(clamp(1, 3), 1);
    equal(clamp(2, 3), 2);
    equal(clamp(3, 3), 0);

    equal(clamp(4, 3), 1);
    equal(clamp(-1, 3), 2);

    equal(sum_coupled_digits("1122"s, 1), 3);
    equal(sum_coupled_digits("1111"s, 1), 4);
    equal(sum_coupled_digits("1234"s, 1), 0);
    equal(sum_coupled_digits("91212129"s, 1), 9);

#include "long_string.h"

    equal(sum_coupled_digits(long_string, 1), 1144);

    equal(sum_halfway_digits("1212"), 6);
    equal(sum_halfway_digits("1221"), 0);
    equal(sum_halfway_digits("123425"), 4);
    equal(sum_halfway_digits("123123"), 12);
    equal(sum_halfway_digits("12131415"), 4);

    cout << "ANSWER: " << sum_halfway_digits(long_string) << endl;

    return 0;
}
