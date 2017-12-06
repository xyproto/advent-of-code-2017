#include "numbers.h"

using namespace std;

Numbers::Numbers(string fn) {
    string line;
    ifstream infile {fn, ifstream::in};
    if (infile.is_open()) {
        while (getline(infile, line)) {
            istringstream is {line};
            _numbers.push_back(
                vector<int>(istream_iterator<int>(is),
                            istream_iterator<int>()));
        }
    }
}

string Numbers::str() {
    stringstream s;
    s << this->width() << "x" << this->height() << " vector of ints: " << endl;
    for (const vector<int> &v : _numbers) {
        auto counter = v.size() - 1;
        for (const int &i : v) {
            s << i;
            if (counter --> 0) { // "go to" operator ;)
                s << ", ";
            }
        }
        s << endl;
    }
    return s.str();
}

bool Numbers::empty() {
    return _numbers.size() == 0;
}

size_t Numbers::width() {
    if (this->empty()) {
        return 0;
    }
    return _numbers[0].size();
}

size_t Numbers::height() {
    if (this->empty()) {
        return 0;
    }
    return _numbers.size();
}

vector<int> Numbers::maxes() {
    vector<int> maxes;
    if (this->empty()) {
        return maxes;
    }
    for (const vector<int> &v : _numbers) {
        int max = v[0];
        for (const int &i : v) {
            if (i > max) {
                max = i;
            }
        }
        maxes.push_back(max);
    }
    return maxes;
}

vector<int> Numbers::mins() {
    vector<int> mins;
    if (this->empty()) {
        return mins;
    }
    for (const vector<int> &v : _numbers) {
        int min = v[0];
        for (const int &i : v) {
            if (i < min) {
                min = i;
            }
        }
        mins.push_back(min);
    }
    return mins;
}

vector<int> Numbers::divs() {
    vector<int> divs;
    if (this->empty()) {
        return divs;
    }
    for (const vector<int> &v : _numbers) {
        // Try all combinations of numbers per row
        for (const int &a : v) {
            for (const int &b : v) {
                if (a == b) {
                    continue;
                }
                if (a % b == 0) {
                    divs.push_back(a / b);
                    break;
                }
            }
        }
    }
    return divs;
}


