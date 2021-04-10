//4) A circle class. There should be at least 3 members in this class: the coordinates of the
//center, the radius and the colors.
//5) A rectangle class. There must be at least two categories of members in this class:
//  the coordinates which decide the location and size of the rectangle, the colors.
//6) A triangle class. You can determine the details of the class.
//7) Other classes as needed. For example, a line class, a polygon class, an arc class
//and etc.

//3) There should be at least two color members in any closed geometric shape class. One
//represents the border color and another represents the fill color
//4) There should be one bool member in any closed geometric shape class to indicate
// whether the shape will be filled with a certain color.
#pragma once
#include"color.h"
#include "point.h"
#include<stack>
#include<vector>
using std::stack;
using std::vector;

class Shape {
 private:
  static unsigned int count;

 public:
  Shape();
  ~Shape();
  virtual void paint() = 0;
};

class Shape_closed :protected Shape{
 private:
  Color border;
  Color fill;
  bool if_fill;

 public:
  Shape_closed(Color border_, Color fill_, bool if_fill_);
  Shape_closed();
  ~Shape_closed();
  Color getBorder();
  Color getFill();
  bool getIf_fill();
  void setBorder(Color border_);
  void setFill(Color fill_);
  void setIf_fill(bool if_fill_);
  virtual void paint() override = 0;
};

class Shape_open : protected Shape {
 private:
  Color border;

 public:
  Shape_open(Color border_);
  Shape_open();
  ~Shape_open();
  Color getBorder();
  void setBorder(Color border_);
  virtual void paint() override =0;
};




class Line:protected Shape_open {
 private:
  Point coo1;
  Point coo2;

 public:
  using Shape_open::Shape_open;
  Line(Point coo1_, Point coo2_, Color border_);
  Line(Point coo1_, Point coo2_);
  ~Line();
  Point getCoo1();
  Point getCoo2();
  void setCoo1(Point coo1_);
  void setCoo2(Point coo2_);
  virtual void paint()override;
};



class Arc : protected Shape_open {
 private:
  Point center;
  int stangle;
  int endangle;
  int radius;
  int height;

 public:
  using Shape_open::Shape_open;
  Arc(Point center_, int st_, int end_, int radius_, int height_,
      Color border_);
  Arc(Point center_, int st_, int end_, int radius_,Color border_);
  Arc(Point center_, int st_, int end_, int radius_);
  ~Arc();
  Point getCenter();
  int getSt();
  int getEnd();
  int getRadius();
  void setCenter(Point center_);
  void setSt(int st_);
  void setEnd(int end_);
  void setRadius(int radius_);
  virtual void paint()override;
};



class Polygon:protected Shape_closed {
 private:
  int n_points;
  stack<Point> endpoints;

 public:
  using Shape_closed::Shape_closed;
  Polygon(stack<Point> endpoints_, Color border_, Color fill_,
          bool if_fill_);
  Polygon(stack<Point> endpoints_, bool if_fill_);
  Polygon(stack<Point> endpoints_);
  ~Polygon();
  int getN_points();
  stack<Point> get_endpoints();
  void setN_points();
  void setEndpoints(stack<Point> endpoints_);
  virtual void paint() override;
};




class Circle :protected Shape_closed{
 private:
  Point center;
  float radius;
  float radius_b;

 public:
  Circle(Point cen_, float rad_, float b_, Color border_, Color fill_,
         bool if_fill_);
  Circle(Point cen_, float rad_, float b_);
  Circle(Point cen_, float rad_, Color border_, Color fill_, bool if_fill_);
  Circle(Point cen_, float rad_);
  ~Circle();
  Point getCen();
  float getRadius();
  float getRadius_b();
  void setCen(Point);
  void setRadius(float);
  void setRadius_b(float);
  virtual void paint() override;
};
//class Rectangle {};
//class Triangle {};
//
//
//void Paint(Shape&);


float int2float(int);