#include"mouse.h"

void control_by_mouse() {
  mouse_msg mouse;
  bool b = 0;
  int x_f{0}, y_f{0};
  while (!keystate('P')) {
    // is_move() �Ƿ�����ƶ���Ϣ������Ϊbool is_down()
    //    �Ƿ���갴��������Ϣ������Ϊbool
    //    is_up() �Ƿ���갴���ſ���Ϣ������Ϊbool

    //    is_left() �Ƿ���������Ϣ������Ϊbool
    //    is_mid() �Ƿ�����м���Ϣ������Ϊbool
    //    is_right() �Ƿ�����Ҽ���Ϣ������Ϊbool

    //    is_wheel() �Ƿ������ֹ�����Ϣ������Ϊbool wheel
    //        �����ֹ���ֵ��һ�������Ϊ 120 �ı�������Լ����
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