#include <iostream>
#include <utility>
#include "numbers.h"
#include "util.h"
#include "vectorfield.h"
#include "turtle.h"

using namespace std;

int main() {
    auto n = Numbers("input.txt");
    cout << n.str() << endl;

    auto vf = Vectorfield(n.width(), n.height());
    cout << vf.str() << endl;
    vf.twirl();
    cout << vf.str() << endl;

}
