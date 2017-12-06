#pragma once

// Create a 2D array of (x, y), where (x, y) is the position to move to next.
// This makes it possible to repeatedly apply the vector field to a 2D array of numbers
// and make them move around, in order to solve Day 3.

#include <vector>
#include <sstream>
#include <optional>
#include "numbers.h"

using namespace std;

using p_t = pair<int, int>; // specifying movement, for instance (1, 0) for moving 1 to the right
using v3d = vector<vector<p_t>>;

class Vectorfield {

private:
    v3d _vf;

public:

    Vectorfield(size_t w, size_t h); // create an empty vectorfield, with all positions set to (0, 0)
    void spiral(); // create a field where all positions points in a spiral into the center
    bool set(size_t x, size_t y, p_t value); // set a value
    optional<p_t> get(size_t x, size_t y); // get a value
    string str();
    size_t width();
    size_t height();

    optional<Numbers> apply(Numbers n); // apply the vectorfield to a 2d vector
};

