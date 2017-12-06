#include <iostream>
#include <utility>
#include "numbers.h"
#include "util.h"
#include "vectorfield.h"

using namespace std;

int main() {
    auto vf = Vectorfield(3, 3);

    cout << "hi" << endl;

    pair<int, int> v {2, 2};
    vf.set(1, 1, v);

    equal(vf.get(1,1), v);

    cout << "ok" << endl;

    cout << vf.str() << endl;

    cout << "And now 9x9 numbers:" << endl;

    auto n = Numbers(3, 3);
    cout << n.str() << endl;

    return 0;
}
