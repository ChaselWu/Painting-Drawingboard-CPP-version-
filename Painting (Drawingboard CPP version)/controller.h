//A controller class for the graphical environment. This class will be responsible for
//initializing the graphical environment, destroying the environment, setting the
//dimensions of the graphical window and etc.
#pragma once
#include<graphics.h>
#include"mouse.h"
#include"button.h"
class Controller {
 public:
  Controller();
  void table_start();
  void run_gra();
};


void init_buttons();