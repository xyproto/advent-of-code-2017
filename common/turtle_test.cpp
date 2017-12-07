#include "test.h"
#include "turtle.h"

using namespace std;

void turtle_test() {
    auto t = Turtle(0, 0, 1, 0);
    cout << t.str() << endl;

    t.left();
    cout << t.str() << endl;

    t.left();
    cout << t.str() << endl;

    t.left();
    cout << t.str() << endl;

    t.left();
    cout << t.str() << endl;
}

int main() {
    turtle_test();
    return 0;
}
