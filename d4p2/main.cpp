#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>
#include "test.h"

using std::vector;
using std::string;
using std::ifstream;
using std::istringstream;

using words_t = vector<string>;

// Split a string into a wordlist
words_t split(const string line, const char sep) {
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
words_t split(const string line) {
    return split(line, ' ');
}

// Remove a letter from a string
// The letter can be anywhere in the string, but only the first match is removed
string remove_letter(const string a, const char b_letter) {
    auto new_string = ""s;
    bool skipped = false;
    for (const char &a_letter : a) {
        if (a_letter == b_letter) {
            if (!skipped) {
                skipped = true;
                continue;
            }
        }
        new_string += a_letter;
    }
    return new_string;
}

// Count the number of a given letter in a given string
int count(const string a, const char l) {
    int counter = 0;
    for (const char &x : a) {
        if (x == l) {
            counter++;
        }
    }
    return counter;
}

// Check if two words are anagrams of each other (equal letter count)
bool anagram_equal(const string a, const string b) {
    const string letters = "abcdefghijklmnopqrstuvwxyz"s;
    for (const char &l : letters) {
        if (count(a, l) != count(b, l)) {
            // lettercount mismatch, not anagram equal
            return false;
        }
    }
    return true;
}

// Count the number of times a word appears in a list of words, with anagram equality
int anagram_count(const words_t words, const string word) {
    auto counter = 0;
    for (const string &x : words) {
        if (anagram_equal(x, word)) {
            counter++;
        }
    }
    return counter;
}

// Check if a given passphrase does not contain anagrams
bool anagram_valid(const string passphrase) {
    auto words = split(passphrase);
    for (const string &word : words) {
        if (anagram_count(words, word) > 1) {
            return false;
        }
    }
    return true;
}

// Count the valid passphrases, wrt anagrams, in the given text file
int anagram_valid_passphrases(const string fn) {
    auto counter = 0;
    string line;
    ifstream infile {fn, ifstream::in};
    if (infile.is_open()) {
        while (getline(infile, line)) {
            istringstream is {line};
            if (anagram_valid(is.str())) {
                counter++;
            }
        }
    }
    return counter;
}

int main() {
    equal(remove_letter("abca"s, 'a'), "bca"s);
    equal(remove_letter("bca"s, 'a'), "bc"s);
    equal(remove_letter("bc"s, 'a'), "bc"s);

    equal(anagram_equal("abcde"s, "fghij"s), false);
    equal(anagram_equal("abcde"s, "ecdab"s), true);
    equal(anagram_equal("oiii"s, "iioi"s), true);

    equal(anagram_valid("oiii iioi"s), false);
    equal(anagram_valid("abcde fghij"s), true);
    equal(anagram_valid("abcde xyz ecdab"s), false);

    equal(anagram_count(split("oiii ioii iioi iiio"s), "oiii"s), 4);

    cout << "so far so good" << endl;

    equal(anagram_count(split("a ab abc abd abf abj"s), "a"s), 1);
    equal(anagram_count(split("a ab abc abd abf abj"s), "ab"s), 1);
    equal(anagram_count(split("a ab abc abd abf abj"s), "abc"s), 1);
    equal(anagram_count(split("a ab abc abd abf abj"s), "abd"s), 1);
    equal(anagram_count(split("a ab abc abd abf abj"s), "abf"s), 1);
    equal(anagram_count(split("a ab abc abd abf abj"s), "abj"s), 1);

    cout << "ok" << endl;

    equal(anagram_valid("a ab abc abd abf abj"s), true);
    equal(anagram_valid("iiii oiii ooii oooi oooo"s), true);

    equal(anagram_valid("oiii ioii iioi iiio"s), false);

    cout << "ANSWER: " << anagram_valid_passphrases("input.txt") << endl;
}
