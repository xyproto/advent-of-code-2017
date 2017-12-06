#include <math.h>
#include "vectorfield.h" // for p_t = pair<int, int>

class Turtle {
private:

  int _x;
  int _y;
  p_t _direction;

public:

  // No bounds check, it's not the Turtle's job

  Turtle(int x, int y, int direction_x, int direction_y);
  Turtle(pair<int, int> pos, pair<int, int> direction);
  void set_direction(p_t v);
  void set_direction(int x, int y);
  p_t get_direction();
  void forward();
  void left();
  bool write(Vectorfield vf);
  void move_turn_write(Vectorfield vf, bool turn_left_after_moving);
  int x();
  int y();
  string str();
};
