#include "memory.h"
#include "util.h"
#include "test.h"

using namespace std;

int main() {
    auto memory = Memory(vector<int> {0, 2, 7, 0});
    cout << memory.str() << endl;

    equal(must(memory.largest()).second, 7);

    cout << "largest memory index: " << must(memory.largest()).first << endl;
    cout << "largest memory value: " << must(memory.largest()).second << endl;

    return 0;
}
