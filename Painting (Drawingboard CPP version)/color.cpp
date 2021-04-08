#include"color.h"

Color::Color(BYTE r_, BYTE g_, BYTE b_) : rr{r_}, gg{g_}, bb{b_} {
  rgb = EGERGB(r_, g_, b_);
}
Color::Color(const Color& c_) : Color(c_.rr, c_.gg, c_.bb) {}
//Color::Color(string s) {
//  s.substr()
//}
Color::Color() : Color(0, 0, 0) {}
Color::~Color() {}
BYTE Color::getR() { return rr; }
BYTE Color::getG() { return gg; }
BYTE Color::Color::getB() { return bb; }
color_t Color::getRGB() { return rgb; }
void Color::setR(BYTE r) { rr = r; }
void Color::setG(BYTE g) { gg = g; }
void Color::setB(BYTE b) { bb = b; }
void Color::setRGB() { rgb = EGERGB(rr, gg, bb); }

