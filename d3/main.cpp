#include <iostream>
#include "util.h"
#include "numbers.h"
#include "vectorfield.h"

using namespace std;

int main() {
    auto vf = Vectorfield(3, 3);

    cout << "hi" << endl;

    pair<int, int> v {2, 2};
    vf.set(1, 1, v);

    equal(vf.get(1,1), v);

    cout << vf.str() << endl;

    return 0;
}
