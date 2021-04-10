#include"shape.h"

Shape::Shape() { count++; }
Shape::~Shape() { count--; }


// private:
//Color border;
//Color fill;
//bool if_fill;
Shape_closed::Shape_closed(Color border_, Color fill_, bool if_fill_)
    : border{border_}, fill{fill_}, if_fill{if_fill_} {}
Shape_closed::Shape_closed() : Shape_closed(Color(), Color(), 0) {}
Shape_closed::~Shape_closed() {}
Color Shape_closed::getBorder() { return border; }
Color Shape_closed::getFill() { return fill; }
bool Shape_closed::getIf_fill() { return if_fill; }
void Shape_closed::setBorder(Color border_) { border = border_; }
void Shape_closed::setFill(Color fill_) { fill = fill_; }
void Shape_closed::setIf_fill(bool if_fill_) { if_fill = if_fill_; }


//private:
//Color border;
Shape_open::Shape_open(Color border_) : border{border_} {}
Shape_open::Shape_open() : Shape_open(Color()) {}
Shape_open::~Shape_open(){}
Color Shape_open::getBorder() { return border; }
void Shape_open::setBorder(Color border_) { border = border_; }


//class Line : protected Shape_open {
// private:
//  Point coo1;
//  Point coo2;
//
// public:
//  using Shape_open::Shape_open;
//};
Line::Line(Point coo1_, Point coo2_, Color border_)
    : coo1{coo1_}, coo2{coo2_}, Shape_open{border_} {}
Line::Line(Point coo1_, Point coo2_) : Line(coo1_, coo2, Color()) {}
Line::~Line() {}
Point Line::getCoo1() { return coo1; }
Point Line::getCoo2() { return coo2; }
void Line::setCoo1(Point coo1_) { coo1 = coo1_; }
void Line::setCoo2(Point coo2_) { coo2 = coo2_; }
void Line::paint() {
  setcolor(getBorder().getARGB());

  ege_line(int2float(coo1.getX()), int2float(coo1.getY()),
           int2float(coo2.getX()), int2float(coo2.getY()));
}


//class Arc : protected Shape_open {
// private:
//  Point center;
//  int stangle;
//  int endangle;
//  int radius;
//
// public:
//  using Shape_open::Shape_open;
//};
Arc::Arc(Point center_, int st_, int end_, int radius_, int height_,
         Color border_)
    : center{center_},
      stangle{st_},
      endangle{end_},
      radius{radius_},
      height{height_},
      Shape_open{border_} {}
Arc::Arc(Point center_, int st_, int end_, int radius_, Color border_)
    : Arc(center_, st_, end_, radius_, radius_, border_) {}

Arc::Arc(Point center_, int st_, int end_, int radius_)
    : Arc(center_, st_, end_, radius_, Color()){}
Arc::~Arc() {}
Point Arc::getCenter() { return center; }
int Arc::getSt() { return stangle; }
int Arc::getEnd() { return endangle; }
int Arc::getRadius() { return radius; }
void Arc::setCenter(Point center_) { center = center_; }
void Arc::setSt(int st_) { stangle = st_; }
void Arc::setEnd(int end_) { endangle = end_; }
void Arc::setRadius(int radius_) { radius = radius_; }
void Arc::paint() {
  setcolor(getBorder().getARGB());
  ege_arc(int2float(center.getX()), int2float(center.getY()), int2float(radius),
          int2float(radius), int2float(stangle), int2float(endangle - stangle));
}



//class Polygon : protected Shape_closed {
// private:
//  int n_points;
//  stack<Point> endpoints;
//
// public:
//  using Shape_closed::Shape_closed;
//};
Polygon::Polygon(stack<Point> endpoints_, Color border_, Color fill_,
                 bool if_fill_)
    : n_points{static_cast<int>(endpoints_.size())},
      endpoints{endpoints_},
      Shape_closed(border_, fill_, if_fill_) {}
Polygon::Polygon(stack<Point> endpoints_, bool if_fill_)
    : Polygon(endpoints_, Color(), Color(), if_fill_){}
Polygon::Polygon(stack<Point> endpoints_) : Polygon(endpoints_, 0){}
Polygon::~Polygon() {}
int Polygon::getN_points() { return n_points; }
stack<Point> Polygon::get_endpoints() { return endpoints; }
void Polygon::setN_points() { n_points = static_cast<int>(endpoints.size()); }
void Polygon::setEndpoints(stack<Point> endpoints_) { endpoints = endpoints_; }
void Polygon::paint() {
  setcolor(getBorder().getARGB());
  if (getIf_fill()) {
    setfillcolor(getFill().getARGB());
  } else {
    setfillcolor(getbkcolor());
  }
  ege_point coo[50];
  stack<Point> endp_ = endpoints;
  for (int i = 0; i < 50; i++) {
    coo[2 * i].x = static_cast<float>(endp_.top().getX());
    coo[2 * i + 1].y = static_cast<float>(endp_.top().getY());
    endpoints.pop();
  }
  ege_fillpoly(n_points, coo);
}























float int2float(int x) {
  float f = static_cast<float>(x);
  return f;
}