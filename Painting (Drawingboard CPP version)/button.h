#pragma once
#include"shape.h"
#include"range.h"
#include<vector>
using std::vector;

//范围（位置，大小） 颜色 反应 交互 is_range

class Button {
 public:
  Range ran;
  Point pos;
  Color border;
  Color fill;
  Color tex;
  Rectangle_ rec;
  LPCSTR text;
  int mode;
  Button(Point pos_,int wid,int height,Color bor_,Color fil_,Color tex_,LPCSTR text_,int mode_);
  Button();
  ~Button(){}
  void show_on_screen();
  //bool is_mouse_on();
  //bool is_mouse_click();
};