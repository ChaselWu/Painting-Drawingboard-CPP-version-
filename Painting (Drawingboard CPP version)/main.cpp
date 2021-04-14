#include "color.h"
#include"shape.h"
#include<iostream>

unsigned int Shape::count = 0;
int main() {
  initgraph(-1, -1);
  ege_enable_aa(true);
  setbkcolor(WHITE);

  mouse_msg mou1, mou2;
  mou1.x = 0;
  mou1.y = 0;
  mou2 = getmouse();
  Color co1{123,234,32,255};
  Color co2{123, 234, 32, 125};
  Rectangle_* r1 = new Rectangle_{Point{100, 200}, Point{400, 600},co1,co1};
  Rectangle_* r2 = new Rectangle_{Point{500, 200}, Point{800, 600}, co2,co2};
  //r->paint();
  //ege_point coo[4];
  //setcolor(BLUE);
  //setfillcolor(BLACK);
  //coo[0].x = 32;
  //coo[0].y = 32;
  //coo[2].x = 645;
  //coo[2].y = 645;
  //coo[1].x = 32;
  //coo[1].y = 645;
  //coo[3].x = 645;
  //coo[3].y = 32;
  //ege_fillpoly(4, coo);
  //getch();
  draw(r1);
  draw(r2);
  while (!keystate('I')) {

      //getmouse();
    mousepos(&(mou1.x), &(mou1.y));
    xyprintf(800, 480,"%d,%d", mou1.x, mou1.y);
  }
  ege::getch();
  ege::closegraph();
  return 0;
}