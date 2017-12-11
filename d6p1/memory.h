#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <optional>
#include <string>
#include "util.h"

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

    // Used together with must(T, U) to return a "not found" value
    pair<index_t, int> NotFound = pair<index_t, int> {-1, -1};

    // Return the largest value, or -1 if not found
    int must_largest_value();
};
