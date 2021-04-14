//A color class. This class represents the colors that can be used in the graphical
//environment. A color class includes 3 components: R for red, G for green and B for
//blue.You may add a member of "color_t" type to the class. However, if you do so, you
//need to add converter functions for converting "RGB" and "color_t".

//BLACK      0               DARKGRAY      0x545454
//BLUE       0x0000A8        LIGHTBLUE     0x5454FC
//GREEN      0x00A800        LIGHTGREEN    0x54FC54
//CYAN       0x00A8A8        LIGHTCYAN     0x54FCFC
//RED        0xA80000        LIGHTRED      0xFC5454
//MAGENTA    0xA800A8        LIGHTMAGENTA  0xFC54FC
//BROWN      0xA8A800        YELLOW        0xFCFC54
//LIGHTGRAY  0xA8A8A8        WHITE	       0xFCFCFC

#pragma once
#include"head.h"
//enum {
//  BLACK,
//  DARKGRAY,
//  BLUE,
//  LIGHTBLUE,
//  GREEN,
//  LIGHTGREEN,
//  CYAN,
//  LIGHTCYAN,
//  RED,
//  LIGHTRED,
//  MAGENTA,
//  LIGHTMAGENTA,
//  BROWN,
//  YELLOW,
//  LIGHTGRAY,
//  WHITE
//};

class Color {
 private:
  BYTE aa;
  BYTE rr;
  BYTE gg;
  BYTE bb;
  color_t rgb;
  color_t argb;

 public:
  Color(BYTE r_, BYTE g_, BYTE b_,BYTE a_);
  Color(BYTE r_, BYTE g_, BYTE b_);
  Color(const Color&);
  //Color(string);
  Color() ;
  ~Color();
  BYTE getA();
  BYTE getR();
  BYTE getG();
  BYTE getB();
  color_t getRGB();
  color_t getARGB();
  void setA(BYTE a);
  void setR(BYTE r);
  void setG(BYTE g);
  void setB(BYTE b);
  void setRGB();
  void setARGB();
};

class Color_mutable : public Color {
  using Color::Color;
};

Color _t2Color(color_t c_t);
color_t Color2_t(Color c);