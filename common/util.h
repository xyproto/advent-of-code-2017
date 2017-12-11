#pragma once

#include <optional>

using namespace std;

// return the last char
optional<const char> last(const string digits);

// must deal with signed ints for the < 0 check to work
// returns an unsigned int
// is not really clamping, since i is wrapped around instead of clamped
template<typename T, typename U>
constexpr T clamp(U i, T length) {
    U signed_length = static_cast<U>(length); // used for dealing with "i" below
    while (i < 0) {
        i += signed_length;
    }
    while (i >= signed_length) {
        i -= signed_length;
    }
    return static_cast<T>(i);
}

// Return the optional value, or the notFoundValue if not
template<typename T>
T must(optional<T> maybeT, T notFoundValue) {
    if (maybeT) {
        return *maybeT;
    }
    return notFoundValue;
}

// Return the integer value, or -1 if nullopt
constexpr int must(optional<int> maybeInt) {
    if (maybeInt) {
        return *maybeInt;
    }
    return -1;
}

