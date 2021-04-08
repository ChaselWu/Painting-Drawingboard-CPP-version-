//4) A circle class. There should be at least 3 members in this class: the coordinates of the
//center, the radius and the colors.
//5) A rectangle class. There must be at least two categories of members in this class: the
//coordinates which decide the location and size of the rectangle, the colors.
//6) A triangle class. You can determine the details of the class.
//7) Other classes as needed. For example, a line class, a polygon class, an arc class and etc.

//3) There should be at least two color members in any closed geometric shape class. One
//represents the border color and another represents the fill color
//4) There should be one bool member in any closed geometric shape class to indicate whether
//the shape will be filled with a certain color.


#pragma once
class Shape {
 private:
  static unsigned int count;
};
class Shape_closed :protected Shape{};
class Shape_open :protected Shape{};