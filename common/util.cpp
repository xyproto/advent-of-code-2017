#include "util.h"

using namespace std;

// return the last char
optional<char> last(string digits) {
    auto dl = digits.length();
    if (dl < 1) {
        return nullopt;
    }
    return optional {digits.at(dl - 1)};
}

// must deal with signed ints for the < 0 check to work
// returns an unsigned int
// is not really clamping, since i is wrapped around instead of clamped
size_t clamp(int64_t i, size_t length) {
    int64_t signed_length = static_cast<int64_t>(length); // used for dealing with "i" below
    while (i < 0) {
        i += signed_length;
    }
    while (i >= signed_length) {
        i -= signed_length;
    }
    return (size_t)i;
}
