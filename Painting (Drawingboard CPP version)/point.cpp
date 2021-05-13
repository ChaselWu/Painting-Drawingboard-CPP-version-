#include"point.h"
Point::Point(int x, int y) : c_x{x}, c_y{y} { setCoord(); }
Point::Point() : Point(0,0) {}
Point::~Point() {}
int Point::getX() { return c_x; }
int Point::getY() { return c_y; }
ege_point Point::getCoord() { return coord; }

void Point::setX(int x) { c_x = x; }
void Point::setY(int y) { c_y = y; }
void Point::setCoord() {
  coord.x = static_cast<float>(c_x);
  coord.y = static_cast<float>(c_y);
}
bool Point::operator==(const Point& p_) {
  if (p_.c_x == c_x && p_.c_y == c_y) {
    return true;
  } else {
    return false;
  }
}