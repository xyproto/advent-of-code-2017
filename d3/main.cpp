#include <iostream>
#include <utility>
#include "numbers.h"
#include "util.h"
#include "vectorfield.h"
#include "turtle.h"

using namespace std;

int main() {
    auto n = Numbers("input.txt");
    cout << n.str() << endl;

    auto vf = Vectorfield(n.width(), n.height());

    auto t = Turtle(2, 2, 1, 0);

    // the left-turn pattern:
    // 1->2: true
    // 2->3: true
    // 3->4: false
    //       true
    //
    // So:  1 1,  0 1  0 1,  0 0 1  0 0 1,  0 0 0 1  0 0 0 1, 0 0 0 0 1  0 0 0 0 1
    //
    for (int i=0; i < 5; ++i) {
        for (int z=0; z < 2; ++z) {
            for (int x=0; x < i; ++x) {
                //cout << "0 ";
                cout << t.str() << endl;
                t.move_turn_write(vf, false);
            }
            //cout << "1, ";
            cout << t.str() << endl;
            t.move_turn_write(vf, true);
        }
    }
    cout << t.str() << endl;
    //cout << endl;

    //// Moving to 2 and setting the direction
    //t.move_turn_write(true); // move, and turn
   ///
    //// Moving to 3 and setting the direction
    //t.move_turn_write(true); // move, and turn

    //// Moving to 4 and setting the direction
    //t.move_turn_write(false); // move, no turn

    //// Moving to 5 and setting the direction
    //t.move_turn_write(true); // move, and turn

    //// Moving to 6 and setting the direction
    //t.move_turn_write(false); // move but don't turn
    //
    //// Moving to 7 and setting the direction
    //t.move_turn_write(true); // move, and turn

    //// Moving to 8 and setting the direction
    //t.move_turn_write(false); // move, and turn



    //vf.set(0, 0, p_t{1, 0});
    //vf.set(1, 0, p_t{1, 0});
    //vf.set(2, 0, p_t{1, 0});
    //vf.set(3, 0, p_t{1, 0});
    //vf.set(4, 0, p_t{0, 1});

    //vf.set(1, 0, p_t{0, -1});
    //vf.set(2, 0, p_t{1, 0});
    //vf.set(3, 0, p_t{1, 0});
    //vf.set(4, 0, p_t{1, 0});
    //vf.set(5, 0, p_t{0, 1});

    cout << vf.str() << endl;

}
