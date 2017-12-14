#include <iostream>
#include <vector>
#include "stringutils.h"
#include "test.h"

using std::vector;
using std::string;

const bool valid(const string passphrase) {
    const auto words = splitc(passphrase);
    for (const string &word : words) {
        if (count(words, word) > 1) {
            return false;
        }
    }
    return true;
}

const unsigned valid_passphrases(const string fn) {
    unsigned counter = 0;
    for (const auto &line: readlines(fn)) {
        if (valid(line)) {
            counter++;
        }
    }
    return counter;
}

int main() {
    equal(valid("aa bb cc dd ee"), true);
    equal(valid("aa bb cc dd aa"), false);
    equal(valid("aa bb cc dd aaa"), true);

    cout << "ANSWER: " << valid_passphrases("input.txt") << endl;
}
