#include"button.h"

//Range ran;
//Point pos;
//Color col;

Button::Button(Point pos_, int wid, int height, Color bor_, Color fil_,
               Color tex_, LPCSTR text_,int mode_)
    : pos{pos_},
      border{bor_},
      fill{fil_},
      tex{tex_},
      ran{0, 0, 0, 0},
      rec{pos, pos},
      text{text_},
      mode{mode_} {
  ran.min_x = pos_.getX() - wid / 2;
  ran.max_x = pos_.getX() + wid / 2;
  ran.min_y = pos_.getY() - height / 2;
  ran.max_y = pos_.getY() + height / 2;
  rec = Rectangle_{Point{ran.min_x, ran.min_y}, Point{ran.max_x, ran.max_y},
                   border, fill};
}
Button::Button():Button(Point(0, 0), 0, 0, Color{}, Color{}, Color{}, "not_init_yet",
               0) {}
void Button::show_on_screen() {
  rec = Rectangle_(Point{ran.min_x, ran.min_y}, Point{ran.max_x, ran.max_y},
                   border, fill);
  draw(&rec);
  settextjustify(LEFT_TEXT, CENTER_TEXT);
  outtextrect(ran.min_x, ran.min_y, (ran.max_x - ran.min_x),
              (ran.max_y - ran.min_y), text);
}