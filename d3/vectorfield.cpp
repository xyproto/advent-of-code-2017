#include "vectorfield.h"

using namespace std;

// Fill a vectorfield with (0,0), given a width and a height.
// TODO: Test that changing a value only affects that value.
Vectorfield::Vectorfield(size_t w, size_t h) {
    p_t zero_zero {0, 0};
    vector<p_t> row;
    for (size_t i=0; i < w; ++i) {
        row.push_back(zero_zero);
    }
    for (size_t i=0; i < h; ++i) {
        _vf.push_back(row);
    }
}

bool Vectorfield::set(size_t x, size_t y, p_t value) {
    if (_vf.size() <= y) {
        return false;
    }
    if (_vf[y].size() <= x) {
        return false;
    }
    _vf[y][x] = value;
    return true;
}

optional<p_t> Vectorfield::get(size_t x, size_t y) {
    if (_vf.size() <= y) {
        return nullopt;
    }
    if (_vf[y].size() <= x) {
        return nullopt;
    }
    return optional {_vf[y][x]};
}

string Vectorfield::str() {
    stringstream s;
    s << this->width() << "x" << this->height() << " vector of (x, y): " << endl;
    for (const auto &row : _vf) {
        auto counter = row.size() - 1;
        for (const auto &p : row) {
            s << "(" << p.first << ", " << p.second << ")";
            if (counter --> 0) { // "go to" operator ;)
                s << ", ";
            }
        }
        s << endl;
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
    // Make a copy of all the values.
    // Some of them might be moved by the vectorfield, some might not.
    auto n_out = n;
    // For each cell in the vectorfield, move the number by the corresponding vector
    for (size_t y=0; y < this->height(); ++y) {
        for (size_t x=0; x < this->width(); ++x) {
            int x_offset = _vf[y][x].first;
            int y_offset = _vf[y][x].second;
            // Get the value from n, but write them to n2
            auto maybeInt = n.get(x, y);
            int value = 0;
            if (maybeInt) {
                value = *maybeInt;
            }
            // Possibly overwrite values in n_out
            n_out.set(x+x_offset, y+y_offset, value);
        }
    }
    // Return an optional with the manipulated numbers
    return optional {n_out};
}
