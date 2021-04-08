#include"point.h"
Point::Point(int x, int y) : c_x{x}, c_y{y} {}
Point::~Point() {}
int Point::getX() { return c_x; }
int Point::getY() { return c_y; }
void Point::setX(int x) { c_x = x; }
void Point::setY(int y) { c_y - y; }