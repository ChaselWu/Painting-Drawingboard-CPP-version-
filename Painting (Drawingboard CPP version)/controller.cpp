#include"controller.h"

//class Controller {
// public:
//  Controller();
//  void table_start();
//  void init_gra();
//  void run();
//  void close_gra();
//};
Controller::Controller() {}
void Controller::table_start() {}
void Controller::init_gra() {
  initgraph(-1, -1);
  ege_enable_aa(true);
  setbkcolor(WHITE);
}
void Controller::run() { control_by_mouse(); }
void Controller::close_gra() {
  ege::getch();
  ege::closegraph();
}