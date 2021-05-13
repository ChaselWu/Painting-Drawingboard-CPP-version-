//ΩÁ√Ê¿‡
#include "button.h"
class Interface {
 public:
  int screen_left, screen_top, screen_right, screen_bottom;
  virtual void get_screen();
  Interface() = default;
  //Interface(int, int);
};

class Db : public Interface {
 public:
  Db();
  ~Db() = default;
  virtual void get_screen() override;
  void set();
  void refresh();
  Button& searchButton(mouse_msg);
  vector<Button> btn_head{};
  vector<Button> btn_column{};
  vector<Button> btn_steps{};
  vector<Button> btn_tools{};
  vector<Button> btn_shapes{};
  vector<Button> btn_colors{};
  vector<Button> btn_color_foot{};
  Button btn_void{
      Button(Point(), 0, 0, Color(), Color(), Color(), "void", 404)};
  Color colors[20][3][10];
  int H1{8};
  int H2{2};
  float per{0};
  float w_catalog{0}, w_menu{0}, w_color_table{0};

  float h_menu{0}, h_tool{0}, h_shape{0}, h_color{0}, h_color_head{0},
      h_color_table{0};

  float wid_head{0}, wid_column{0}, wid_steps{0}, wid_shapes{0}, wid_colors{0},
      wid_color_foot{0};

  float h_head{0}, h_column{0}, h_steps{0}, h_shapes{0}, h_colors{0};
  float h_color_foot{0};
 // void show();
};