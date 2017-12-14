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
        if (x > max_value) { // Must be > and not >= in order to find the first value that is the largest, not the final largest one
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

void Memory::redistribute() {
    auto largest_item = this->largest();
    if (largest_item) {
        // it's a *pair
        size_t largest_pos = largest_item->first;
        auto largest_val = largest_item->second;
        // empty the memory location with the first largest value and put it in the pocket
        unsigned pocket = static_cast<unsigned>(largest_val);
        _memory[largest_pos] = 0;

        //cout << "rem " << this->str() << endl;

        size_t length = _memory.size();

        // share the pocket money between all positions that are not the largest value position
        unsigned share = static_cast<unsigned>(round(static_cast<double>(pocket) / static_cast<double>(length - 1)));

        // as long as there are enough money in the pocket to redistribute a share of the wealth
        for (size_t i=1; i < length; i++) {
            auto next_pos_opt = transform(i, largest_pos, length);
            if (!next_pos_opt) {
                continue;
            }
            auto next_pos = *next_pos_opt;
            // Break if we can no longer redistribute a share from the pocket
            if (pocket < share) {
                break;
            }
            // Move a share from the pocket to a memory position
            pocket -= share;
            _memory[next_pos] += share;
        }
        // Move the remaining money to the position of the previously largest value
        _memory[largest_pos] += pocket;
    }
}

vector<int> Memory::get() {
    return _memory;
}

// Find how many times the largest value can be redistributed without the situation repeating itself
optional<unsigned> Memory::redistribution_number(unsigned max_iterations) {
    auto start_state = _memory;
    vector<vector<int>> seen;
    for (unsigned counter = 1; counter <= max_iterations; counter++) {
        seen.push_back(_memory);
        this->redistribute();
        for (const auto &old: seen) {
            if (old == _memory) {
                // set the state back to what it was
                _memory = start_state;
                // return the number of iterations until the situation repeated itself
                return optional<unsigned> {counter};
            }
        }
    }
    // set the state back to what it was
    _memory = start_state;
    // looped too many times
    return nullopt;
}

// Find how many times the largest value can be redistributed without the situation repeating itself
// Assumes it will work out without ending up in an endless loop (!) or consuming all available memory (!)
unsigned Memory::must_redistribution_number() {
    cout << "fst " << this->str() << endl;
    auto start_state = _memory;
    vector<vector<int>> seen;
    unsigned counter = 0;
    while (true) {
        counter++;
        seen.push_back(_memory);
        this->redistribute();
        cout << "add " << this->str() << endl;
        for (const auto &old: seen) {
            if (_memory == old) {
                cout << "fin " << this->str() << endl;
                // set the state back to what it was
                _memory = start_state;
                // return the number of iterations until a situation repeats itself
                return counter;
            }
        }
    }
}

// Find the number of loops until the start position is seen again
unsigned Memory::must_redistribution_number_full() {
    //cout << "fst " << this->str() << endl;
    auto start_state = _memory;
    unsigned counter = 0;
    while (true) {
        counter++;
        this->redistribute();
        //cout << "add " << this->str() << endl;
        if (_memory == start_state) {
            //cout << "fin " << this->str() << endl;
            // return the number of iterations until the situation is the same as the first one
            return counter;
        }
    }
}

