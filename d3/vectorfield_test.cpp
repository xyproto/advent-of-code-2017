#include "vectorfield.h"
#include "test.h"

using namespace std;

int main() {
    // Create a 3x3 vectorfield
    auto vf = Vectorfield(3, 3);
    
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

    // Output the vectorfield
    cout << vf.str() << endl;

    return 0;
}
