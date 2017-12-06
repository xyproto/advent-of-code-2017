#include "main.h"

using namespace std;

int main() {
    //test_basic_functionality();

    auto n = Numbers("input.txt");
    cout << n.str() << endl;

    auto vf = Vectorfield(n.width(), n.height());
    cout << vf.str() << endl;
}
