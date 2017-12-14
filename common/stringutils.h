#include <algorithm>
#include <cctype>
#include <locale>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>

using std::string;
using std::isspace;
using std::find_if;
using std::pair;
using std::vector;
using std::ifstream;
using std::istringstream;

using namespace std::literals;

// Trim functions from:
// https://stackoverflow.com/a/217605/131264

// trim from start (in place)
inline void _ltrim(string &s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch) {
        return !isspace(ch);
    }));
}

// trim from end (in place)
inline void _rtrim(string &s) {
    s.erase(find_if(s.rbegin(), s.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
inline void _trim(string &s) {
    _ltrim(s);
    _rtrim(s);
}

// trim from start (copying)
inline const string ltrim(string s) {
    _ltrim(s);
    return s;
}

// trim from end (copying)
inline const string rtrim(string s) {
    _rtrim(s);
    return s;
}

// trim from both ends (copying)
inline const string trim(string s) {
    _trim(s);
    return s;
}

// --- end of trim functions from stackoverflow ---

// length of a string, inspired by Go and Python
inline const unsigned len(const string s) {
    return s.length();
}

// Split a string into two pairs
const pair<string, string> split(const string line, const string sep) {
    bool afterSep = false;
    bool match;
    pair<string, string> retval {""s, ""s};
    for (unsigned i=0; i < len(line); i++) {
        if (i >= len(line)) {
            break;
        }
        if (line[i] == sep[0]) {
            // Found a first match, check the rest
            match = true;
            for (unsigned i2=0; i2 < len(sep); i2++) {
                if (i+i2 >= len(line)) {
                    match = false;
                    break;
                }
                if (line[i+i2] != sep[i2]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                afterSep = true;
            }
            i += len(sep);
        }
        if (i >= len(line)) {
            break;
        }
        if (afterSep) {
            retval.second += line[i];
        } else {
            retval.first += line[i];
        }
    }
    return retval;
}

// Split a string into a vector of strings
const vector<string> splitv(const string line, const string sep) {
    unsigned retcounter = 0;
    vector<string> retval {""s};
    bool match;
    for (unsigned i=0; i < len(line); i++) {
        if (line[i] == sep[0]) {
            // Found a first match, check the rest
            match = true;
            for (unsigned i2=0; i2 < len(sep); i2++) {
                if (i+i2 >= len(line)) {
                    match = false;
                    break;
                }
                if (line[i+i2] != sep[i2]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                retcounter++;
                retval.push_back(""s);
            }
            i += len(sep);
        }
        if (i >= len(line) || retcounter >= retval.size()) {
            break;
        }
        retval[retcounter] += line[i];
    }
    return retval;
}

// Trim all words in a vector of strings
const vector<string> trimv(const vector<string> words, const bool remove_empty) {
    vector<string> trimmed_words {};
    string trimmed_word;
    for (const auto &word: words) {
        trimmed_word = trim(word);
        if (len(trimmed_word) > 0) {
            trimmed_words.push_back(trimmed_word);
        }
    }
    return trimmed_words;
}

// Split a string into words
inline const vector<string> words(const string line) {
    return trimv(splitv(line, " "), true);
}

// Split a string into words, and also take a string separator
inline const vector<string> words(const string line, const string sep) {
    return trimv(splitv(line, sep), true);
}

// Split a string into a wordlist
const vector<string> splitc(const string line, const char sep) {
    vector<string> words;
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
inline const vector<string> splitc(string line) {
    return splitc(line, ' ');
}

// Count the number of times a word appears in a list of words
inline const unsigned count(const vector<string> words, const string word) {
    auto counter = 0;
    for (const string &x : words) {
        if (x == word) {
            counter++;
        }
    }
    return counter;
}

// Count the number of times a char appears in a word
inline const unsigned count(const string word, const char letter) {
    auto counter = 0;
    for (const char &x : word) {
        if (x == letter) {
            counter++;
        }
    }
    return counter;
}

// Read in all the lines in a text file.
// Quick and dirty, no particular error checking.
const vector<string> readlines(const string filename) {
    vector<string> lines {};
    string line;
    ifstream infile {filename, ifstream::in};
    if (infile.is_open()) {
        while (getline(infile, line)) {
            istringstream is {line};
            lines.push_back(is.str());
        }
    }
    return lines;
}

// Check if a vector<string> has the given string
bool has(vector<string> words, string word) {
    for (const auto &w: words) {
        if (w == word) {
            return true;
        }
    }
    return false;
}


