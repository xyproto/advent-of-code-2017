#include <iostream>
#include <vector>
#include "test.h"
#include <fstream>
#include <iterator>
#include <sstream>

using namespace std;

using words_t = vector<string>;

// Split a string into a wordlist
words_t split(string line, const char sep) {
    words_t words;
    auto word = ""s;
    for (const char &letter : line) {
        if (letter == sep) {
            words.push_back(word);
            word = ""s;
            continue;
        }
        word += letter;
    }
    if (word.length() > 0) {
        words.push_back(word);
    }
    return words;
}

// Split a string into a words
words_t split(string line) {
    return split(line, ' ');
}

// Count the number of times a word appears in a list of words
int count(words_t words, string word) {
    auto counter = 0;
    for (const string &x : words) {
        if (x == word) {
            counter++;
        }
    }
    return counter;
}

bool valid(string passphrase) {
    auto words = split(passphrase);
    for (const string &word : words) {
        if (count(words, word) > 1) {
            return false;
        }
    }
    return true;
}

int valid_passphrases(string fn) {
    auto counter = 0;
    string line;
    ifstream infile {fn, ifstream::in};
    if (infile.is_open()) {
        while (getline(infile, line)) {
            istringstream is {line};
            if (valid(is.str())) {
                counter++;
            }
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
