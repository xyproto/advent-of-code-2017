#include <iostream>
#include <vector>
#include <sstream>
#include "test.h"
#include "program.h"
#include "util.h"

using namespace std;

int main() {
    auto prog1 = Program(vector<int> {0, 3, 0, 1, -3}, part2);
    prog1.run(5);
    cout << prog1.str() << endl;

    auto prog2 = Program(vector<int> {0, 3, 0, 1, -3}, part2);
    prog2.run(500);
    cout << prog2.str() << endl;

    cout << "ANSWER: " << Program("input.txt", part2).run() << endl;
}
