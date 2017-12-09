#include <iostream>
#include <vector>
#include <sstream>
#include "test.h"
#include "util.h"
#include "memory.h"

using namespace std;

int main() {
    auto memory = Memory();

    auto largest_bank = memory.largest_bank();

    cout << largest_bank.str() << endl;
}
