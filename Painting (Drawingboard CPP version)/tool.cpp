#include"tools.h"

//class Pen : public Tool {
// private:
//  Color color;
//  bool has_pen_down;
//};

Pen::Pen(Color c_) : color{c_} {}
Pen::Pen() : Pen(Color()) {}
Color Pen::getColor() { return color; }
bool Pen::is_pen_down() { return has_pen_down; }
void Pen::setColor(Color c_) { color = c_; }
void Pen::pen_down() { has_pen_down = true; }
void Pen::pen_up() { has_pen_down = false; }