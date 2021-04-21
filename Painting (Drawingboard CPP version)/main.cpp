#include "color.h"
#include"shape.h"
#include"button.h"
#include"mouse.h"
#include"controller.h"
#include<iostream>

unsigned int Shape::count = 0;
int main() {
  Controller con;
  con.table_start();
  con.init_gra();
  con.run();
  con.close_gra();
  //Color co1{5, 4, 5, 250};
  //Color co2{123, 234, 32, 125};
  //Color co3{23, 123, 53, 78};
  return 0;
}