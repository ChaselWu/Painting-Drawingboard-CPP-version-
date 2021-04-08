#pragma once

//A point class.This class represents the 2d coordinates of a point

class Point {
 private:
  int c_x;
  int c_y;

 public:
  Point(int, int);
  ~Point();
  int getX();
  int getY();
  void setX(int);
  void setY(int);
};