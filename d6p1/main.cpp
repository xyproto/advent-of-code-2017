#include <iostream>
#include <vector>
#include <sstream>
#include "test.h"
#include "util.h"
#include "memory.h"

using namespace std;

int main() {
    auto memory = Memory(16);

    //auto largest = memory.largest();

    cout << memory.str() << endl;
}
