#include "memory.h"
#include "util.h"
#include "test.h"

int main() {
    using std::vector;
    using std::cout;

    auto memory = Memory(vector<int> {0, 2, 7, 0});
    cout << memory.str() << endl;

    equal(must(memory.largest(), memory.NotFound).second, 7);
    equal(memory.must_largest_value(), 7);
    equal(memory.must_largest_position(), static_cast<index_t>(2));

    return 0;
}
