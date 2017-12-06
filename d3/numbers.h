#pragma once

#include <fstream>
#include <vector>
#include <iterator>
#include <sstream>
#include <optional>

using namespace std;

using v2d = vector<vector<int>>;

class Numbers {

private:
    v2d _numbers;

public:

    Numbers(string fn); // read a file with a matrix of space and newline separated numbers (ints)
    Numbers(int w, int h); // initialize a certain size with zeros

    string str(); // return a string with a header and the contents of the 2d vector
    size_t width();
    size_t height();
    bool empty();
    vector<int> maxes(); // maximum number per row
    vector<int> mins(); // minimum number per row
    vector<int> divs(); // result of dividing the numbers that can be divided per row

    bool set(size_t x, size_t y, int value); // returns true if x and y were within range
    optional<int> get(size_t x, size_t y); // returns a value, if possible
};

