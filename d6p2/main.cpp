#include <iostream>
#include <vector>
#include <sstream>
#include "test.h"
#include "util.h"
#include "memory.h"

using std::cout;

int main() {
    cout << "ANSWER: " << endl << Memory(vector<int> {2, 8, 8, 5, 4, 2, 3, 1, 5, 5, 1, 2, 15, 13, 5, 14}).must_redistribution_cycles() << endl;
}
