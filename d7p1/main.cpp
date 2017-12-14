#include <iostream>
#include <vector>
#include <sstream>
#include "test.h"
#include "util.h"
#include "stringutils.h"
#include "memory.h"

using std::cout;

//
// If a word is pointing to others, but nobody is pointing to that word, it's the top word
//
//----------------------------

const vector<string> others(const string line) {
    return words(split(line, "->").second, ", ");
}

const string word(const string line) {
    return trim(split(line, "->").first);
}

bool has(vector<string> words, string word) {
    for (const auto &w: words) {
        if (w == word) {
            return true;
        }
    }
    return false;
}

const vector<string> top_words(vector<string> lines) {
    vector<string> pointed_to {}; // words that have been pointed too
    vector<string> pointing {}; // words that are pointing to other words
    vector<string> all_words {};
    for (const auto &line: lines) {
        const auto word = words(line)[0];
        all_words.push_back(word);
        const auto other_words = others(line);
        //cout << word << " => ";
        if (other_words.size() > 0) {
            // This word is pointing at other words
            pointing.push_back(word);
        }
        for (const auto &other_word: other_words) {
            //cout << other_word << "; ";
            // Add the word to the list of words that has been pointed too
            pointed_to.push_back(other_word);
        }
        //cout << endl;
    }
    // Top words are not pointed to, but pointing
    vector<string> top_words {};
    for (const auto &word: all_words) {
        if (has(pointing, word) && !has(pointed_to, word)) {
            top_words.push_back(word);
        }
    }
    return top_words;
}

int main() {
    cout << "--- input.txt ---" << endl;
    for (const auto &tw: top_words(readlines("input.txt"))) {
        cout << "top word: " << tw << endl;
    }

    cout << "--- input2.txt ---" << endl;
    for (const auto &tw: top_words(readlines("input2.txt"))) {
        cout << "top word: " << tw << endl;
    }
}
