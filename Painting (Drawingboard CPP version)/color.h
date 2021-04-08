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
  BYTE rr;
  BYTE gg;
  BYTE bb;
  color_t rgb;

 public:
  Color(BYTE, BYTE, BYTE);
  Color(const Color&);
  Color(string);
  Color() ;
  ~Color();
  BYTE getR();
  BYTE getG();
  BYTE getB();
  color_t getRGB();
  void setR(BYTE);
  void setG(BYTE);
  void setB(BYTE);
  void setRGB();
};

class Color_mutable : protected Color {
  using Color::Color;
};