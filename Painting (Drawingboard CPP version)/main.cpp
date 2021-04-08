#include "color.h"
int main() {
  initgraph(640, 480);
  circle(200, 200, 100);
  color_t w = EGERGB(232,134,34);
  color_t k = EGERGB(EGEGET_R(w), EGEGET_G(w), EGEGET_B(w));
  for (;;) {
    setbkcolor(k);
    getch();
  }
  closegraph();
  return 0;
}