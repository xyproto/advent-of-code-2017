#include "memory.h"

Bank::Bank(vector<int> numbers) {
    _blocks = numbers;
}

size_t Bank::length() {
    return _blocks.size();
}

string Bank::str() {
    stringstream s;
    s << "[";
    size_t counter = 0;
    for (const int &x: _blocks) {
        s << x;
        if (++counter != _blocks.size()) {
            s << ", ";
        }
    }
    s << "]" << endl;
    return s.str();
}

Memory::Memory() {
    for (int i=0; i < 16; i++) {
        _banks.push_back(Bank(vector<int> {}));
    }
}

Bank Memory::largest_bank() {
    // 16 banks must be initialized in the constructor
    auto &largest_so_far = _banks[0];
    for (auto &b: _banks) {
        if (b.length() > largest_so_far.length()) {
            largest_so_far = b;
        }
    }
    return largest_so_far;
}
