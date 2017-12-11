#include <iostream>
#include "test.h"
#include "util.h"
#include "numbers.h"

int main() {
    auto n2 = Numbers("input_small.txt");
    auto divs = n2.divs();

    equal(divs[0], static_cast<int>(4));
    equal(divs[1], static_cast<int>(3));
    equal(divs[2], static_cast<int>(2));

    auto sumdivs = 0;
    for (const int &x : divs) {
        sumdivs += x;
    }
    equal(sumdivs, 9);

    auto n = Numbers("input_large.txt");
    divs = n.divs();
    sumdivs = 0;
    for (const int &x : divs) {
        sumdivs += x;
    }
    cout << "answer: " << sumdivs << endl;

    return 0;
}
