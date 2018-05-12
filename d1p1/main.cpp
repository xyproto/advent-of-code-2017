#include <iostream>
#include <cstdlib>
#include <optional>
#include "test.h"

using std::string;
using std::optional;
using std::nullopt;

using sum_t = unsigned int; // uint64_t

// sum_digits sums the digits in the given std::string and returns an integer of type sum_t
sum_t sum_digits(string digits) {
    sum_t total = 0;
    for (const auto &digit : digits) {
        total += digit - '0';
        cout << "sum this far: " << total << endl;
    }
    return total;
}

// return the last char
optional<char> last(string digits) {
    auto dl = digits.length();
    if (dl < 1) {
        return nullopt;
    }
    return optional {digits.at(dl - 1)};
}

// sum_equal_digits returns a sum of the digits that are equal to the next one
sum_t sum_equal_digits(string digits) {
    auto equal_digits = ""s; // a list of equal digits, as std::string
    auto prev_digit = last(digits); // start with the last digit, since the digit list is supposed to be circular
    for (const auto &digit : digits) {
        if (digit == prev_digit) {
            equal_digits += digit;
        }
        prev_digit = digit;
    }
    return sum_digits(equal_digits);
}

int main() {
    equal(sum_equal_digits("1122"s), static_cast<sum_t>(3));
    equal(sum_equal_digits("1111"s), static_cast<sum_t>(4));
    equal(sum_equal_digits("1234"s), static_cast<sum_t>(0));
    equal(sum_equal_digits("91212129"s), static_cast<sum_t>(9));

    #include "../include/long_string.inc"

    equal(sum_equal_digits(long_string), static_cast<sum_t>(1144));
    return 0;
}
