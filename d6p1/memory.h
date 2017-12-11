#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <optional>
#include <string>

using namespace std;

using index_t = size_t;

class Memory {

private:
    vector<int> _memory;

public:
    Memory(vector<int> memory);
    Memory(size_t size);

    string str();
    optional<pair<index_t, int>> largest();
};
