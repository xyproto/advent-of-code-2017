#include <iostream>
#include "util.h"
#include "numbers.h"

using namespace std;

int main() {
    auto n = Numbers("input.txt");
    cout << n.str() << endl;
    for (const int &x : n.maxes()) {
        cout << "max " << x << endl;
    }
    for (const int &x : n.mins()) {
        cout << "min " << x << endl;
    }

    auto maxes = n.maxes();
    auto mins = n.mins();
    equal(maxes.size(), mins.size());

    for (size_t i=0; i < n.height(); i++) {
        cout << "min " << mins[i] << " max " << maxes[i] << endl;
    }

    int diffsum = 0;
    for (size_t i=0; i < n.height(); i++) {
        auto diff = maxes[i] - mins[i];
        diffsum += diff;
    }

    cout << "diffsum: " << diffsum << endl;

    return 0;
}
