#pragma once

// Create a 2D array of (x, y), where (x, y) is the position to move to next.
// This makes it possible to repeatedly apply the vector field to a 2D array of numbers
// and make them move around, in order to solve Day 3.

#include <vector>
#include <sstream>
#include <optional>
#include "numbers.h"

using namespace std;

using v3d = vector<vector<pair<int, int>>>;

class Vectorfield {

private:
    v3d _vf;

public:

    Vectorfield(int w, int h); // create an empty vectorfield, with all positions set to (0, 0)
    void spiral(); // create a field where all positions points in a spiral into the center
    void set(int x, int y, pair<int, int> v); // set a value
    pair<int, int> get(int x, int y); // get a value
    string str();
    size_t width();
    size_t height();

    optional<Numbers> apply(Numbers n); // apply the vectorfield to a 2d vector
};

