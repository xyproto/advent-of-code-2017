#include <algorithm> 
#include <cctype>
#include <locale>

// Thanks https://stackoverflow.com/a/217605/131264 for the following trim functions:

// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

// trim from start (copying)
static inline std::string ltrim_copy(std::string s) {
    ltrim(s);
    return s;
}

// trim from end (copying)
static inline std::string rtrim_copy(std::string s) {
    rtrim(s);
    return s;
}

// trim from both ends (copying)
static inline std::string trim_copy(std::string s) {
    trim(s);
    return s;
}

// --- end of trim functions ---




unsigned len(string s) {
    return s.length();
}

pair<string, string> split(string line, string sep) {
    bool afterSep = false;
    pair<string, string> retval {""s, ""s};
    for (unsigned i=0; i < len(line); i++) {
        if (i >= len(line)) {
            break;
        }
        if (line[i] == sep[0]) {
            // Found a first match, check the rest
            auto match = true;
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

vector<string> splitv(string line, string sep) {
    unsigned retcounter = 0;
    vector<string> retval {""s};
    for (unsigned i=0; i < len(line); i++) {
        if (line[i] == sep[0]) {
            // Found a first match, check the rest
            auto match = true;
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

vector<string> trimv(vector<string> words) {
    vector<string> trimmed_words {};
    for (auto &word: words) {
        trimmed_words.push_back(trim_copy(word));
    }
    return trimmed_words;
}


