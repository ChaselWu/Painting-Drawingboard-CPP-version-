//Ìí¼ÓARBG

#include"color.h"

Color::Color(BYTE r_, BYTE g_, BYTE b_, BYTE a_)
    : aa{a_}, rr{r_}, gg{g_}, bb{b_} {
  rgb = EGERGB(r_, g_, b_);
  argb = EGERGBA( r_, g_, b_,a_);
}
Color::Color(const Color& c_) : Color(c_.rr, c_.gg, c_.bb, c_.aa) {}
Color::Color(BYTE r_, BYTE g_, BYTE b_) : Color(r_, g_, b_, 255) {}
//Color::Color(string s) {
//  s.substr()
//}
Color::Color() : Color(0, 0, 0) {}
Color::~Color() {}
BYTE Color::getA() { return aa; }
BYTE Color::getR() { return rr; }
BYTE Color::getG() { return gg; }
BYTE Color::Color::getB() { return bb; }
color_t Color::getRGB() { return rgb; }
color_t Color::getARGB() { return argb; }
void Color::setA(BYTE a) { aa = a; }
void Color::setR(BYTE r) { rr = r; }
void Color::setG(BYTE g) { gg = g; }
void Color::setB(BYTE b) { bb = b; }
void Color::setRGB() { rgb = EGERGB(rr, gg, bb); }
void Color::setARGB() { argb = EGERGBA(rr, gg, bb, aa); }

Color _t2Color(color_t c_t) {
  Color c{EGEGET_R(c_t), EGEGET_G(c_t), EGEGET_B(c_t)};
  return c;
}
color_t Color2_t(Color c) {
  color_t c_t = EGERGB(c.getR(), c.getG(), c.getB());
  return c_t;
}