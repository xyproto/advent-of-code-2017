#include <iostream>
#include "numbers.h"
#include "test.h"
#include "util.h"

int main() {
    const int number_preceeding_the_result = 368078;
    int result;
    for (int size=0; size < 10; ++ size) {
        // TODO, memoize previous and smaller sizes, or expand the dimentions while twirling
        result = next_twirl_sum_number(size, number_preceeding_the_result);
        if (result != -1) {
            cout << "RESULT AT SIZE " << size << ": " << result << endl;
            break;
        }
    }
    return 0;
}
