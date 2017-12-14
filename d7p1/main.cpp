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

vector<string> others(string line) {
    auto rightpart = split(line, "->").second;
    vector<string> words = splitv(rightpart, ", ");
    return trimv(words);
}

string word(string line) {
}


int main() {
    auto line = "fwft (72) -> ktlj, cntj, xhth"s;
    for (auto &word: others(line)) {
        cout << "WORD: " << word << endl;
    }
    cout << line << endl;
}
