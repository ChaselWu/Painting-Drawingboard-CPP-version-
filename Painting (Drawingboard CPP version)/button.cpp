#include"button.h"

//Range ran;
//Point pos;
//Color col;

Button::Button(Point pos_, int wid, int height, Color bor_, Color fil_,
               Color tex_, LPCSTR text_)
    : pos{pos_},
      border{bor_},
      fill{fil_},
      tex{tex_},
      ran{0, 0, 0, 0},
      rec{pos, pos},
      text{text_},
      but{} {
  ran.min_x = pos_.getX() - wid / 2;
  ran.max_x = pos_.getX() + wid / 2;
  ran.min_y = pos_.getY() - height / 2;
  ran.max_y = pos_.getY() + height / 2;
  rec = Rectangle_{Point{ran.min_x, ran.min_y}, Point{ran.max_x, ran.max_y},
                   border, fill};
  but = text;
}
void Button::show_on_screen() {
  draw(&rec);
  settextjustify(CENTER_TEXT, CENTER_TEXT);
  outtextrect(ran.min_x, ran.min_y, (ran.max_x - ran.min_x),
              (ran.max_y - ran.min_y), text);
}
void Button::mouse_on() {

}
void Button::mouse_click() {}

vector<Point> pos_colu1;
const int wid_colu1 = 30, height_colu1 = 60;
const Color
void init_buttons() { colunm1.push_back(Button{Point{15,30},30,60}) }