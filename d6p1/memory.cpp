#include "memory.h"

Memory::Memory(size_t memory_size) {
    for (size_t i=0; i < memory_size; i++) {
        _memory.push_back(bank_t{block_t{}});
    }
}

bank_t Memory::largest() {
    // 16 banks must be initialized in the constructor
    auto &largest_bank_so_far = _memory[0];
    for (auto &bank: _memory) {
        if (bank.size() > largest_bank_so_far.size()) {
            largest_bank_so_far = bank;
        }
    }
    return largest_bank_so_far;
}

string Memory::str() {
    stringstream s;
    s << "Memory" << endl;
    s << "------" << endl;
    size_t counter0 = 0;
    for (auto &bank: _memory) {
        size_t counter1 = 0;
        s << "bank " << counter0++ << ":" << endl << "\t<";
        for (const auto &block: bank) {
            s << "block: [";
            size_t counter2 = 0;
            for (const int &x: block) {
                s << x;
                if (++counter2 != block.size()) {
                    s << ", ";
                }
            }
            s << "]";
            if (++counter1 != bank.size()) {
                s << endl;
            }
        }
        s << ">" << endl;
    }
    return s.str();
}


