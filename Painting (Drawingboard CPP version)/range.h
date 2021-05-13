//ËÄÎ¬ is_range
#include"point.h"
class Range {
 public:
  int min_x;
  int max_x;
  int min_y;
  int max_y;
  bool is_in_range(Point p_);
  Range(int min_x_, int max_x_,int min_y_,int max_y_);
  Range();
  ~Range(){};
};