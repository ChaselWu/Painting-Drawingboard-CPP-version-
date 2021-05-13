//2) Add a copy constructor and destructor in each class.(finished)
//4) Customize the destructor in each class to show the objects of the class which are alive
//The "color" member in any geometric shape class MUST be created with "new" operator and
//destroyed with "delete" operator. Other members in geometric shape class may be
//created/destroyed with new/delete.
//Any geometric shape object should be created with "new" and destroyed with "delete".
#pragma once
#include"color.h"
#include "point.h"
#include<stack>
#include<array>
using std::stack;
using std::array;

class Shape {
 private:
  static unsigned int count;

 public:
  Shape();
  Shape(const Shape&);
  Shape& operator=(const Shape&);
  ~Shape();
  virtual void paint() = 0;
  virtual void setColor() = 0;
  unsigned int getCount() const;

};

class Shape_closed :public Shape{
 private:
  Color* border = new Color{};
  Color* fill = new Color();
  bool if_fill;

 public:
  Shape_closed(Color border_, Color fill_, bool if_fill_);
  Shape_closed();
  Shape_closed(const Shape_closed&);
  Shape_closed& operator=(const Shape_closed&);
  ~Shape_closed();
  Color getBorder()const;
  Color getFill()const;
  bool getIf_fill()const;
  void setBorder(Color border_);
  void setFill(Color fill_);
  void setIf_fill(bool if_fill_);
  virtual void paint() override = 0;
  virtual void setColor() override;
};

class Shape_open : public Shape {
 private:
  Color* border = new Color();

 public:
  Shape_open(Color border_);
  Shape_open(const Shape_open&);
  Shape_open& operator=(const Shape_open&);
  Shape_open();
  ~Shape_open();
  Color getBorder()const;
  void setBorder(Color border_);
  virtual void paint() override =0;
  virtual void setColor() override;
};




class Line:public Shape_open {
 private:
  Point coo1;
  Point coo2;

 public:
  using Shape_open::Shape_open;
  Line(Point coo1_, Point coo2_, Color border_);
  Line(Point coo1_, Point coo2_);
  Line(const Line&);
  ~Line();
  Point getCoo1()const;
  Point getCoo2()const;
  void setCoo1(Point coo1_);
  void setCoo2(Point coo2_);
  virtual void paint()override;
};



class Arc_ : public Shape_open {
 private:
  Point center;
  int stangle;
  int endangle;
  int radius;
  int height;

 public:
  using Shape_open::Shape_open;
  Arc_(Point center_, int st_, int end_, int radius_, int height_,
      Color border_);
  Arc_(Point center_, int st_, int end_, int radius_,Color border_);
  Arc_(Point center_, int st_, int end_, int radius_);
  Arc_(const Arc_&);
  ~Arc_();
  Point getCenter()const;
  int getSt()const;
  int getEnd()const;
  int getRadius()const;
  int getHeight() const;
  void setCenter(Point center_);
  void setSt(int st_);
  void setEnd(int end_);
  void setRadius(int radius_);
  virtual void paint()override;
};



class Polygon_:public Shape_closed {
 private:
  int n_points;
  stack<Point> endpoints;

 public:
  using Shape_closed::Shape_closed;
  Polygon_(stack<Point> endpoints_, Color border_, Color fill_,
          bool if_fill_);
  Polygon_(stack<Point> endpoints_, bool if_fill_);
  Polygon_(stack<Point> endpoints_);
  Polygon_(const Polygon_&);
  ~Polygon_();
  int getN_points()const;
  stack<Point> get_endpoints()const;
  void setN_points();
  void setEndpoints(stack<Point> endpoints_);
  virtual void paint() override;
};




class Circle :public Shape_closed{
 private:
  Point center;
  float radius;
  float radius_b;

 public:
  using Shape_closed::Shape_closed;
  Circle(Point cen_, float rad_, float b_, Color border_, Color fill_,
         bool if_fill_);
  Circle(Point cen_, float rad_, float b_);
  Circle(Point cen_, float rad_, Color border_, Color fill_, bool if_fill_);
  Circle(Point cen_, float rad_);
  Circle(const Circle&);
  ~Circle();
  Point getCen()const;
  float getRadius()const;
  float getRadius_b()const;
  void setCen(Point);
  void setRadius(float);
  void setRadius_b(float);
  void setRadius_b();
  virtual void paint() override;
};


class Triangle:public Shape_closed {
 private:
  array<Point, 3> endpoints{Point(0, 0), Point(0, 0), Point(0, 0)};
 public:
  using Shape_closed::Shape_closed;
  Triangle(Point a, Point b, Point c, Color border_, Color fill_,
            bool if_fill_);
  Triangle(Point a, Point b, Point c);
  Triangle(const Triangle&);
  ~Triangle();
  array<Point, 3> getEndpoints()const;
  void setEndpoints(Point a, Point b, Point c);
  virtual void paint() final;
};

class Rectangle_ : public Shape_closed {
 private:
  array<Point, 2> endpoints{Point(0, 0), Point(0, 0)};

 public:
  using Shape_closed::Shape_closed;
  Rectangle_(Point a, Point b, Color border_, Color fill_,
           bool if_fill_);
  Rectangle_(Point a, Point b, Color border_, Color fill_);
  Rectangle_(Point a, Point b, Color border_);
  Rectangle_(Point a, Point b);
  Rectangle_(const Rectangle_&);
  ~Rectangle_();
  array<Point, 2> getEndpoints()const;
  void setEndpoints(Point a, Point b);
  virtual void paint() final;
};


void draw(Shape*);
float int2float(int);