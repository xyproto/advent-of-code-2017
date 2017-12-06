#include <iostream>
#include "util.h"
#include "numbers.h"

using namespace std;

int main() {
    auto n2 = Numbers("input2.txt");
    auto divs = n2.divs();
    equal(divs[0], 4);
    equal(divs[1], 3);
    equal(divs[2], 2);
    auto sumdivs = 0;
    for (const int &x : divs) {
        sumdivs += x;
    }
    equal(sumdivs, 9);

    auto n = Numbers("input.txt");
    divs = n.divs();
    sumdivs = 0;
    for (const int &x : divs) {
        sumdivs += x;
    }
    cout << "answer: " << sumdivs << endl;

    return 0;
}
