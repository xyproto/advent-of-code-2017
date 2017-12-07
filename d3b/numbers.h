#pragma once

#include <fstream>
#include <vector>
#include <iterator>
#include <sstream>
#include <optional>
#include "turtle.h"

using namespace std;

using v2d = vector<vector<int>>;

using p_t = pair<int, int>; // specifying movement, for instance (1, 0) for moving 1 to the right
using v3d = vector<vector<p_t>>;

class Numbers {

private:
    v2d _numbers;

public:

    Numbers(string fn); // read a file with a matrix of space and newline separated numbers (ints)
    Numbers(int w, int h); // initialize a certain size with zeros
    Numbers(int w); // initialize a certain size with zeros

    string str(); // return a string with a header and the contents of the 2d vector
    size_t width();
    size_t height();
    bool empty();
    vector<int> maxes(); // maximum number per row
    vector<int> mins(); // minimum number per row
    vector<int> divs(); // result of dividing the numbers that can be divided per row

    bool set(size_t x, size_t y, int value); // returns true if x and y were within range
    optional<int> get(size_t x, size_t y); // returns a value, if possible

    int center(); // the center value

    optional<p_t> find(int value); // finds the position of a value
    optional<int> manhattan(int value); // finds the manhattan distance from the value, if found, to the center

    optional<Numbers*> twirl(); // add a twirl

    bool write(Turtle* t, int value); // write a value at the turtle position
};

