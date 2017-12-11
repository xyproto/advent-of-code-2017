#include <iostream>
#include <vector>
#include <sstream>
#include "test.h"
#include "program.h"
#include "util.h"

int main() {
    auto p = Program(vector<int> {0, 3, 0, 1, -3}, part1);
    p.run(5);

    cout << "ANSWER: " << Program("input.txt", part1).run() << endl;
}
