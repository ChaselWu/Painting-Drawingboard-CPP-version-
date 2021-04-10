// A point class.This class represents the 2d coordinates of a point
#pragma once
#include<graphics.h>



class Point {
 private:
  int c_x;
  int c_y;
  ege_point coord;

 public:
  Point(int, int);
  ~Point();
  int getX();
  int getY();
  ege_point getCoord();
  void setX(int x);
  void setY(int y);
  void setCoord();
};