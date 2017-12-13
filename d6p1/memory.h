#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <optional>
#include <string>
#include <cmath>
#include "util.h"

using std::vector;
using std::string;
using std::optional;
using std::pair;
using std::nullopt;
using std::stringstream;
using std::endl;
using std::cout;

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
    pair<index_t, int> NotFound = pair<index_t, int> {0, -1};

    // Return the largest value, or -1 if not found
    int must_largest_value();

    // Return the position with the largest value or 0 if not found
    index_t must_largest_position();

    // Redistribute the largest one on the others
    void redistribute();

    // Return the contents
    vector<int> get();

    // Return the number of iterations of redistribution until the result has been seen before
    optional<unsigned> redistribution_number(unsigned max_iterations);

    // Same as redistribution_number, but without any safeguards (!)
    unsigned rn();
};
