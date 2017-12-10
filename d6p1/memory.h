#pragma once

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

using block_t = vector<int>;
using bank_t = vector<block_t>;
using memory_t = vector<bank_t>;

class Memory {

private:
    memory_t _memory;

public:
    Memory(size_t memory_size);

    bank_t largest();
    size_t length();
    string str();

};
