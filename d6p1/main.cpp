#include <iostream>
#include <vector>
#include <sstream>
#include "test.h"
#include "util.h"
#include "memory.h"

int main() {
    using std::cout;

    auto memory = Memory(16);

    //auto largest = memory.largest();

    cout << memory.str() << endl;
}
