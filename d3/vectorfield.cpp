#include "vectorfield.h"

using namespace std;

// Fill a vectorfield with (0,0), given a width and a height.
// TODO: Test that changing a value only affects that value.
Vectorfield::Vectorfield(int w, int h) {
    pair<int, int> zero_zero {0, 0};
    vector<pair<int, int>> row;
    for (int i=0; i < w; ++i) {
        row.push_back(zero_zero);
    }
    for (int i=0; i < h; ++i) {
        _vf.push_back(row);
    }
}

void Vectorfield::set(int x, int y, pair<int, int> v) {
    _vf[y][x] = v;
}

pair<int, int> Vectorfield::get(int x, int y) {
    return _vf[y][x];
}

string Vectorfield::str() {
    stringstream s;
    for (const auto &row : _vf) {
        for (const auto &p : row) {
            s << "(" << p.first << ", " << p.second << ")" << endl;
        }
    }
    return s.str();
}

size_t Vectorfield::height() {
    return _vf.size();
}

size_t Vectorfield::width() {
    if (this->height() == 0) {
        return 0;
    }
    return _vf[0].size();
}

// apply the vectorfield to a 2d vector
// returns a pair with a v2d and an error, if an error happened
optional<Numbers> Vectorfield::apply(Numbers n) {
    if (n.width() != this->width() || n.height() != this->height()) {
        // Size mismatch, return an optional with no value
        return nullopt;
    }
    // TODO: Return an optional with the manipulated numbers
    return nullopt;
}
