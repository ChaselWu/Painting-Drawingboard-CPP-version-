#include"shape.h"

Shape::Shape() { count++; }
Shape::Shape(const Shape&) { count++; }
Shape& Shape::operator=(const Shape& s_) { return *this; }
Shape::~Shape() { count--; }
unsigned int Shape::getCount() const { return count; }

// private:
//Color border;
//Color fill;
//bool if_fill;
Shape_closed::Shape_closed(Color border_, Color fill_, bool if_fill_)
    : if_fill{if_fill_} {
  *border = {border_};
  *fill = {fill_};
}
Shape_closed::Shape_closed() : Shape_closed(Color(), Color(), 0) {}
Shape_closed::Shape_closed(const Shape_closed& s_) : Shape_closed(s_.getBorder(),s_.getFill(),s_.getIf_fill()){}
Shape_closed& Shape_closed::operator=(const Shape_closed& s_) {
  *border = *s_.border;
  *fill = *s_.fill;
  if_fill = s_.if_fill;
  return *this;
}
Shape_closed::~Shape_closed() {
  delete border;
  delete fill;
  border = nullptr;
  fill = nullptr;
}
Color Shape_closed::getBorder()const { return *border; }
Color Shape_closed::getFill()const { return *fill; }
bool Shape_closed::getIf_fill() const{ return if_fill; }
void Shape_closed::setBorder(Color border_) { *border = border_; }
void Shape_closed::setFill(Color fill_) { *fill = fill_; }
void Shape_closed::setIf_fill(bool if_fill_) { if_fill = if_fill_; }
void Shape_closed::setColor() {
  setcolor(getBorder().getARGB());
  if (getIf_fill()) {
    setfillcolor(getFill().getARGB());
  } else {
    setfillcolor(getbkcolor());
  }
}

//private:
//Color border;
Shape_open::Shape_open(Color border_) { *border = {border_}; }
Shape_open::Shape_open(const Shape_open& s_) : Shape_open(s_.getBorder()) {}
Shape_open& Shape_open::operator=(const Shape_open& s_) {
  *border = *s_.border;
  return *this;
}
Shape_open::Shape_open() : Shape_open(Color()) {}
Shape_open::~Shape_open() {
  delete border;
  border = nullptr;
}
Color Shape_open::getBorder()const { return *border; }
void Shape_open::setBorder(Color border_) { *border = border_; }
void Shape_open::setColor() { setcolor(getBorder().getARGB()); }

//class Line : public Shape_open {
// private:
//  Point coo1;
//  Point coo2;
//
// public:
//  using Shape_open::Shape_open;
//};
Line::Line(Point coo1_, Point coo2_, Color border_)
    : coo1{coo1_}, coo2{coo2_}, Shape_open{border_} {}
Line::Line(Point coo1_, Point coo2_) : Line(coo1_, coo2_, Color()) {}
Line::Line(const Line& l_) : Line(l_.getCoo1(),l_.getCoo2(),l_.getBorder()) {}
Line::~Line() {}
Point Line::getCoo1()const { return coo1; }
Point Line::getCoo2()const { return coo2; }
void Line::setCoo1(Point coo1_) { coo1 = coo1_; }
void Line::setCoo2(Point coo2_) { coo2 = coo2_; }
void Line::paint() {
  //setcolor(getBorder().getARGB());

  ege_line(int2float(coo1.getX()), int2float(coo1.getY()),
           int2float(coo2.getX()), int2float(coo2.getY()));
}


//class Arc_ : public Shape_open {
// private:
//  Point center;
//  int stangle;
//  int endangle;
//  int radius;
//
// public:
//  using Shape_open::Shape_open;
//};
Arc_::Arc_(Point center_, int st_, int end_, int radius_, int height_,
         Color border_)
    : center{center_},
      stangle{st_},
      endangle{end_},
      radius{radius_},
      height{height_},
      Shape_open{border_} {}
Arc_::Arc_(Point center_, int st_, int end_, int radius_, Color border_)
    : Arc_(center_, st_, end_, radius_, radius_, border_) {}

Arc_::Arc_(Point center_, int st_, int end_, int radius_)
    : Arc_(center_, st_, end_, radius_, Color()){}
Arc_::Arc_(const Arc_& a_) :Arc_(a_.getCenter(),a_.getSt(),a_.getEnd(),a_.getRadius(),a_.getHeight(),a_.getBorder()) {}
Arc_::~Arc_() {}
Point Arc_::getCenter()const { return center; }
int Arc_::getSt()const { return stangle; }
int Arc_::getEnd()const { return endangle; }
int Arc_::getRadius()const { return radius; }
int Arc_::getHeight() const { return height; }
void Arc_::setCenter(Point center_) { center = center_; }
void Arc_::setSt(int st_) { stangle = st_; }
void Arc_::setEnd(int end_) { endangle = end_; }
void Arc_::setRadius(int radius_) { radius = radius_; }
void Arc_::paint() {
  ege_arc(int2float(center.getX()) - int2float(radius),
          int2float(center.getY()) - int2float(radius),
          int2float(radius) * 2, int2float(radius) * 2, int2float(stangle),
          int2float(endangle - stangle));
}



//class Polygon_ : public Shape_closed {
// private:
//  int n_points;
//  stack<Point> endpoints;
//
// public:
//  using Shape_closed::Shape_closed;
//};
Polygon_::Polygon_(stack<Point> endpoints_, Color border_, Color fill_,
                 bool if_fill_)
    : n_points{static_cast<int>(endpoints_.size())},
      endpoints{endpoints_},
      Shape_closed(border_, fill_, if_fill_) {}
Polygon_::Polygon_(stack<Point> endpoints_, bool if_fill_)
    : Polygon_(endpoints_, Color(), Color(), if_fill_){}
Polygon_::Polygon_(stack<Point> endpoints_) : Polygon_(endpoints_, 0){}
Polygon_::Polygon_(const Polygon_& p_):Polygon_(p_.get_endpoints(),p_.getBorder(),p_.getFill(),p_.getIf_fill()) {}
Polygon_::~Polygon_() {}
int Polygon_::getN_points()const { return n_points; }
stack<Point> Polygon_::get_endpoints()const { return endpoints; }
void Polygon_::setN_points() { n_points = static_cast<int>(endpoints.size()); }
void Polygon_::setEndpoints(stack<Point> endpoints_) { endpoints = endpoints_; }
void Polygon_::paint() {
  ege_point coo[50];
  stack<Point> endp_ = endpoints;
  for (int i = 0; i < 50; i++) {
    coo[2 * i].x = static_cast<float>(endp_.top().getX());
    coo[2 * i + 1].y = static_cast<float>(endp_.top().getY());
    endpoints.pop();
  }
  ege_fillpoly(n_points, coo);
  for (int i = 0; i < n_points; i++) {
    ege_line(coo[i].x, coo[i].y, coo[(i + 1) % n_points].x, coo[(i + 1) % n_points].y);
  }
}



//class Circle : public Shape_closed {
// private:
//  Point center;
//  float radius;
//  float radius_b;
//
// public:
//  using Shape_closed::Shape_closed;
//};
Circle::Circle(Point cen_, float rad_, float b_, Color border_, Color fill_,
               bool if_fill_)
    : center{cen_},
      radius{rad_},
      radius_b{b_},
      Shape_closed(border_, fill_, if_fill_) {}
Circle::Circle(Point cen_, float rad_, float b_)
    : Circle(cen_, rad_, b_, Color(), Color(), 0) {}
Circle::Circle(Point cen_, float rad_, Color border_, Color fill_,
               bool if_fill_)
    : Circle(cen_, rad_, rad_, border_, fill_, if_fill_) {}

Circle::Circle(Point cen_, float rad_) : Circle(cen_, rad_, rad_) {}
Circle::Circle(const Circle& c_):Circle(c_.getCen(),c_.getRadius(),c_.getRadius_b(),c_.getBorder(),c_.getFill(),c_.getIf_fill()) {}
Circle::~Circle() {}
Point Circle::getCen()const { return center; }
float Circle::getRadius()const { return radius; }
float Circle::getRadius_b()const { return radius_b; }
void Circle::setCen(Point p) { center = p; }
void Circle::setRadius(float f) { radius = f; }
void Circle::setRadius_b(float f) { radius_b = f; }
void Circle::setRadius_b() { radius_b = radius; }
void Circle::paint() {
  ege_ellipse(center.getX() - radius , center.getY() - radius_b,
              radius * 2, radius_b * 2);
}


//class Triangle : public Shape_closed {
// private:
//  array<Point, 3> endpoints;
// public:
//  using Shape_closed::Shape_closed;
//};
Triangle::Triangle(Point a, Point b, Point c, Color border_, Color fill_,
                   bool if_fill_)
    : Shape_closed{border_, fill_, if_fill_} {
  endpoints.at(0) = a;
  endpoints.at(1) = b;
  endpoints.at(2) = c;
}
Triangle::Triangle(Point a, Point b, Point c)
    : Triangle(a, b, c, Color(), Color(), 0) {}
Triangle::Triangle(const Triangle& t_):Triangle(t_.getEndpoints().at(0),t_.getEndpoints().at(1),t_.getEndpoints().at(2),t_.getBorder(),t_.getFill(),t_.getIf_fill()) {}
Triangle::~Triangle() {}
array<Point, 3> Triangle::getEndpoints()const { return endpoints; }
void Triangle::setEndpoints(Point a, Point b, Point c) {
  endpoints.at(0) = a;
  endpoints.at(1) = b;
  endpoints.at(2) = c;
}
void Triangle::paint() {
  ege_point coo[3];
  for (int i = 0; i < 3; i++) {
    coo[i] = endpoints.at(i).getCoord();
  }
  ege_fillpoly(3, coo);
  for (int i = 0; i < 3; i++) {
    ege_line(coo[i].x, coo[i].y, coo[(i + 1) % 3].x, coo[(i + 1) % 3].y);
  }
}





//class Rectangle_ : public Shape_closed {
// private:
//  array<Point, 2> endpoints{Point(0, 0), Point(0, 0)};
//
// public:
//  using Shape_closed::Shape_closed;
//};
Rectangle_::Rectangle_(Point a, Point b, Color border_, Color fill_, bool if_fill_)
    : Shape_closed{border_, fill_, if_fill_} {
  endpoints.at(0) = a;
  endpoints.at(1) = b;
}
Rectangle_::Rectangle_(Point a, Point b, Color border_, Color fill_)
    : Rectangle_(a, b, border_, fill_, true) {}
Rectangle_::Rectangle_(Point a, Point b, Color border_)
    : Rectangle_(a, b, border_, border_, 0) {}
Rectangle_::Rectangle_(Point a, Point b)
    : Rectangle_{a, b, Color(), Color(), 0} {}
Rectangle_::Rectangle_(const Rectangle_& r_):Rectangle_(r_.getEndpoints().at(0),r_.getEndpoints().at(1),r_.getBorder(),r_.getFill(),r_.getIf_fill()) {}
Rectangle_::~Rectangle_() {}
array<Point, 2> Rectangle_::getEndpoints()const { return endpoints; }
void Rectangle_::setEndpoints(Point a, Point b) {
  endpoints.at(0) = a;
  endpoints.at(1) = b;
}
void Rectangle_::paint() {
  ege_point coo[4];
  coo[0] = endpoints.at(0).getCoord();
  coo[2] = endpoints.at(1).getCoord();
  coo[1].x = endpoints.at(0).getCoord().x;
  coo[1].y = endpoints.at(1).getCoord().y;
  coo[3].x = endpoints.at(1).getCoord().x;
  coo[3].y = endpoints.at(0).getCoord().y;
  ege_fillpoly(4, coo);
  for (int i = 0; i < 4; i++) {
    ege_line(coo[i].x, coo[i].y, coo[(i + 1) % 4].x, coo[(i + 1) % 4].y);
  }
}

void draw(Shape* s_) {
  s_->setColor();
  s_->paint();
}

float int2float(int x) {
  float f = static_cast<float>(x);
  return f;
}