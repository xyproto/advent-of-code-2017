#include <iostream>
#include <cstdlib>
#include <optional>
#include "test.h"
#include "util.h"

using sum_t = unsigned int; // uint64_t

// sum_digits sums the digits in the given string and returns an integer of type sum_t
sum_t sum_digits(string digits) {
    sum_t total = 0;
    for (const auto &digit : digits) {
        total += digit - '0';
        cout << "sum this far: " << total << endl;
    }
    return total;
}

// sum_coupled_digits returns a sum of the digits that are equal to the +offset one
// has clamping and wraparound, so an offset of 1 or 100 will still work, regardless of
// the length of the given string of digits
sum_t sum_coupled_digits(string digits, const int64_t offset) {
    // a list of digit couples (neighbours, if offset is 1), as string
    auto digit_couples = ""s;
    char digit, other_digit;
    for (size_t i=0; i < digits.length(); i++) {
        digit = digits.at(i);
        // clamp must accept signed ints, because "i - offset" may be signed and < 0
        other_digit = digits.at(clamp(static_cast<int64_t>(i - offset), static_cast<size_t>(digits.length())));
        if (digit == other_digit) {
            digit_couples += digit;
        }
    }
    return sum_digits(digit_couples);
}

sum_t sum_halfway_digits(string digits) {
    const int64_t offset = digits.length() / 2;
    return sum_coupled_digits(digits, offset);
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

    equal(sum_coupled_digits("1122"s, 1), static_cast<sum_t>(3));
    equal(sum_coupled_digits("1111"s, 1), static_cast<sum_t>(4));
    equal(sum_coupled_digits("1234"s, 1), static_cast<sum_t>(0));
    equal(sum_coupled_digits("91212129"s, 1), static_cast<sum_t>(9));

    #include "../include/long_string.inc"

    equal(sum_coupled_digits(long_string, 1), static_cast<sum_t>(1144));

    equal(sum_halfway_digits("1212"), static_cast<sum_t>(6));
    equal(sum_halfway_digits("1221"), static_cast<sum_t>(0));
    equal(sum_halfway_digits("123425"), static_cast<sum_t>(4));
    equal(sum_halfway_digits("123123"), static_cast<sum_t>(12));
    equal(sum_halfway_digits("12131415"), static_cast<sum_t>(4));

    cout << "ANSWER: " << sum_halfway_digits(long_string) << endl;

    return 0;
}
