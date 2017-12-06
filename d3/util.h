#pragma once

#include <stdlib.h>

using namespace std;

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

template<typename T>
void equal(T a, T b) {
    if (a == b) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        exit(EXIT_FAILURE);
    }
}
