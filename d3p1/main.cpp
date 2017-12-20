#include <iostream>
#include "numbers.h"
#include "test.h"

int manhattan(int value) {
    auto n = Numbers(static_cast<int>(sqrt(value))+2);
    n.twirl();
    auto distanceMaybe = n.manhattan(value);
    if (distanceMaybe) {
        return *distanceMaybe;
    }
    // Not found
    return -1;
}

int main() {
    equal(manhattan(1), 0);
    equal(manhattan(12), 3);
    equal(manhattan(23), 2);
    equal(manhattan(1024), 31);

    cout << "Answer: " << manhattan(368078) << endl; // 371! :)
    return 0;
}
