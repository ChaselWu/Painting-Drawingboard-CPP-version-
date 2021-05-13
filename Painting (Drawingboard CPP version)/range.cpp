#include"range.h"

bool Range::is_in_range(Point p_) {
  bool a = ((p_.getX() > min_x) && (p_.getX() < max_x));
  bool b = ((p_.getY() > min_y) && (p_.getY() < max_y));
  return a && b;
  ;
}
Range::Range(int min_x_, int max_x_, int min_y_, int max_y_)
    : min_x{min_x_}, max_x{max_x_}, min_y{min_y_}, max_y{max_y_} {}
Range::Range() : Range(0, 0, 0, 0) {}