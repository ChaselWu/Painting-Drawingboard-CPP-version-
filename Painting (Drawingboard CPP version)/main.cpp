#include "color.h"
#include"shape.h"
#include"button.h"
#include"mouse.h"
#include"controller.h"
#include"interface.h"
#include<iostream>

unsigned int Shape::count = 0;
int main() {
  Controller con;
  //con.table_start();
  con.run_gra();
  return 0;
}