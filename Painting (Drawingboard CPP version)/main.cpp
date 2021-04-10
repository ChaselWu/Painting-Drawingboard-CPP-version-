#include "color.h"
#include"shape.h"
unsigned int Shape::count = 0;
int main() {
  initgraph(640, 480);
  ege_enable_aa(true);
  circle(200, 200, 100);
  Point po1{12, 12}, po2{50, 50};
  Line l(po1, po2);

  color_t w = EGERGB(232,134,34);
  color_t k = EGERGB(EGEGET_R(w), EGEGET_G(w), EGEGET_B(w));
  for (;;) {
    setbkcolor(k);
    l.paint();
    ege_arc(75, 75, 50, 50, 0, 90);
    getch();
  }
  closegraph();
  return 0;
}