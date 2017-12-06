#include "main.h"

using namespace std;

void test_basic_functionality() {
    // Create a vectorfield and matrix
    auto vf = Vectorfield(3, 3);
    auto n = Numbers(3, 3);

    // Test basic set and get for the vectorfield
    pair<int, int> v {1, 1};
    vf.set(1, 1, v);
    auto maybePair = vf.get(1,1);
    if (maybePair) {
        equal(*maybePair, v);
    } else {
        cout << "FAIL" << endl;
        exit(EXIT_FAILURE);
    }

    // Test basic set and get for the matrix
    int vi = 1;
    n.set(1, 1, vi);
    auto maybeInt = n.get(1,1);
    if (maybeInt) {
        equal(*maybeInt, vi);
    } else {
        cout << "FAIL" << endl;
        exit(EXIT_FAILURE);
    }

    // Output vectorfield and matrix
    cout << vf.str() << endl;
    cout << n.str() << endl;
}


