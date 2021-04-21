//
//pen brush
//color
//--------------------------------------------------------------------------

#pragma once
#include"color.h"

class Tool {
};
class Pen : public Tool {
 private:
  Color color;
  bool has_pen_down{0};

 public:
  Pen();
  Pen(Color);
  Color getColor();
  bool is_pen_down();
  void setColor(Color);
  void pen_down();
  void pen_up();
};