#include "numbers.h"
#include "test.h"

using namespace std;

int main() {
    // Create a 3x3 matrix
    auto n = Numbers(3, 3);

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

    // Output the matrix
    cout << n.str() << endl;

    return 0;
}
