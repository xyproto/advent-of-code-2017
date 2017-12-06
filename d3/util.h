#pragma once

#include <stdlib.h>
#include <optional>
#include <iostream>

using namespace std;

// return the last char
optional<char> last(string digits);

// must deal with signed ints for the < 0 check to work
// returns an unsigned int
// is not really clamping, since i is wrapped around instead of clamped
size_t clamp(int64_t i, size_t length);

template<typename T>
void equal(T a, T b) {
    if (a == b) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        exit(EXIT_FAILURE);
    }
}
