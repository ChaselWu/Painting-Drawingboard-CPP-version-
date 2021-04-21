#include"mouse.h"

void control_by_mouse() {
  mouse_msg mouse;
  bool b = 0;
  int x_f{0}, y_f{0};
  while (!keystate('P')) {
    // is_move() 是否鼠标移动消息，类型为bool is_down()
    //    是否鼠标按键按下消息，类型为bool
    //    is_up() 是否鼠标按键放开消息，类型为bool

    //    is_left() 是否鼠标左键消息，类型为bool
    //    is_mid() 是否鼠标中键消息，类型为bool
    //    is_right() 是否鼠标右键消息，类型为bool

    //    is_wheel() 是否鼠标滚轮滚动消息，类型为bool wheel
    //        鼠标滚轮滚动值，一般情况下为 120 的倍数或者约数。
    mouse = getmouse();
    if (keystate('I')) {
      xyprintf(800, 480, "%d,%d,%d", mouse.x, mouse.y, mouse.is_up());
    }
    switch (mouse.is_left()) {
      case 1:
        b = !b;
    }
    if (b) {
      putpixel(mouse.x, mouse.y, BLUE);
    }
    // switch ()
  }
}