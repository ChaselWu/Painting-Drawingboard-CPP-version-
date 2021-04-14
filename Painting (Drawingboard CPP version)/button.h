#pragma once
#include"shape.h"
#include"range.h"


//范围（位置，大小） 颜色 反应 交互 is_range

class Button {
 public:
  Range ran;
  Point pos;
  Color border;
  Color fill;
  Rectangle_ rec;
  Button(Point pos_,int wid,int height,Color bor_,Color fil_);
  ~Button(){}
  void show_on_screen();
  //bool mouse_on();
  //bool mouse_click();
};

