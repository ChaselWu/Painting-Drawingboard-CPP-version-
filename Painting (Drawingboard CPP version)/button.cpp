#include"button.h"

//Range ran;
//Point pos;
//Color col;

Button::Button(Point pos_, int wid, int height, Color bor_,Color fil_)
    : pos{pos_}, border{bor_}, fill {fil_}, ran{0, 0, 0, 0}, rec{pos, pos} {
  ran.min_x = pos_.getX() - wid / 2;
  ran.max_x = pos_.getX() + wid / 2;
  ran.min_y = pos_.getY() - height / 2;
  ran.max_y = pos_.getY() + height / 2;
  rec = Rectangle_{Point{ran.min_x, ran.min_y}, Point{ran.max_x, ran.max_y},
                   border, fill};
}
void Button::show_on_screen() { draw(&rec); }
//void Button::mouse_on() {
//
//}
//void Button::mouse_click() {}