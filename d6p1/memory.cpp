#include "memory.h"

Memory::Memory(vector<int> memory) {
    _memory = memory;
}

// Create an empty memory of size "size"
Memory::Memory(size_t size) {
    for (size_t x=0; x < size; x++) {
        _memory.push_back(0);
    }
}

// Return the index and value of the largest value
optional<pair<index_t, int>> Memory::largest() {
    if (_memory.size() == 0) {
        return nullopt;
    }
    index_t counter = 0;
    auto max_index = counter;
    auto max_value = _memory[max_index];
    for (const int &x: _memory) {
        if (x > max_value) {
            max_value = x;
            max_index = counter;
        }
        counter++;
    }
    return optional {pair<index_t, int> {max_index, max_value}};
}

// Return the largest value, or -1 if not found
int Memory::must_largest_value() {
    return must(this->largest(), this->NotFound).second;
}

// Return the largest value, or -1 if not found
index_t Memory::must_largest_position() {
    return must(this->largest(), this->NotFound).first;
}

string Memory::str() {
    stringstream s;
    s << "Memory" << endl;
    s << "------" << endl;
    s << "[";
    size_t counter = 0;
    for (auto &x: _memory) {
        s << x;
        if (++counter != _memory.size()) {
            s << ", ";
        }
    }
    s << "]";
    return s.str();
}
