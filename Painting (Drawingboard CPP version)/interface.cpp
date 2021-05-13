#include"interface.h"
void Interface::get_screen() {
  getviewport(&screen_left, &screen_top, &screen_right, &screen_bottom, NULL,
              NULL);
}
//vector<Button> btn_head;
//vector<Button> column;
//vector<Button> steps;
//vector<Button> tools;
//vector<Button> shapes;
//Color colors[10][3][10];
//Point pos_, int wid, int height, Color bor_, Color fil_, Color tex_,
//    LPCSTR text_, int mode_
Db::Db() { memset(colors,0,60); }
void Db::get_screen() {
  getviewport(&screen_left, &screen_top, &screen_right, &screen_bottom, NULL,
              NULL);
  per =
      min(float(screen_right) / float(3.0), float(screen_bottom) / float(2.0)) /
      float(300.0);
  w_catalog = 30 * per;
  w_menu = 180 * per;
  w_color_table = 140 * per;
  h_menu = 35 * per;
  h_tool = 130 * per;
  h_shape = 130 * per;
  h_color = 185 * per;
  h_color_head = 20 * per;
  h_color_table = 64 * per;
  wid_head = 30 * per;
  wid_column = 45 * per;
  wid_steps = 30 * per;
  wid_shapes = 50 * per;
  wid_colors = 14 * per;
  wid_color_foot = 7 * per;
  h_head = 21*per, h_column =14*per, h_steps = 14*per,
  h_shapes = 55*per, h_colors = 14*per;
  h_color_foot = 22 * per;
  Point pos_head[4];
  for (int i = 0; i < 4; i++) {
    pos_head[4 - i - 1] =
        Point(screen_right - wid_head / 2 - wid_head * i, h_head / 2);
  }
  Point pos_column[2] = {Point(wid_column / 2, h_column / 2 + h_head),
                         Point(wid_column / 2 * 3, h_column / 2 + h_head)};
  Point pos_steps[3];
  for (int i = 0; i < 3; i++) {
    pos_steps[i] = Point(wid_column * 2 + wid_steps * i + wid_steps / 2,
                         h_steps / 2 + h_head);
  }
  Point pos_shapes[6];
  for (int i = 0; i < 6; i++) {
    pos_shapes[i] =
        Point((55 + 50 * (i % 3)) * per, (202 + 55 * (i / 3)) * per);
  }
  Point pos_colors[6][10];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 10; j++) {
      pos_colors[i][j] = Point(w_catalog + 5 + wid_colors / 2 + wid_colors * j,
                               (322 + 14 * i) * per);
    }
  }
  for (int i = 3; i < 6; i++) {
    for (int j = 0; j < 10; j++) {
      pos_colors[i][j] = Point(w_catalog + 5 + wid_colors / 2 + wid_colors * j,
                               (406 + 14 * (i % 3)) * per);
    }
  }
  Point pos_color_foot[40];
  for (int i = 0; i < 20; i++) {
    pos_color_foot[i] = Point(
        w_catalog + 5 + wid_color_foot / 2 + wid_color_foot * i, 368 * per);
  }
  for (int i = 20; i < 40; i++) {
    pos_color_foot[i] =
        Point(w_catalog + 5 + wid_color_foot / 2 + wid_color_foot * (i % 20),
              452 * per);
  }

  LPCSTR t_head[4] = {"", "", "", "关闭"};
  LPCSTR t_column[2] = {"菜单", "绘图"};
  LPCSTR t_steps[3] = {"清", "撤", "还"};
  // LPCSTR t_tools[]
  LPCSTR t_shapes[6] = {"直线", "弧线", "圆", "多边形", "矩形", "三角形"};
  LPCSTR t_colors[20][3][10];

  for (int i = 0; i < 20; i++) {
    float h = float(22.49) * i;
    for (int j = 0; j < 3; j++) {
      float s = float(0.5 + 0.25 * j);
      for (int k = 0; k < 10; k++) {
        float l = float(0.11) * k;
        colors[i][j][k] = _t2Color(hsl2rgb(h, s, l));
        t_colors[i][j][k] = "" + i * 30 + j * 10 + k;
      }
    }
  }

  color_t* temp = new color_t(getcolor());
  setcolor(BLACK);
  line(screen_right / 5, h_menu, screen_right / 5, screen_bottom);
  line(0, h_menu, screen_right / 5, h_menu);
  line(0, h_menu + h_tool, w_menu, h_menu + h_tool);
  line(0, h_menu + h_tool + h_shape, w_menu, h_menu + h_tool + h_shape);
  xyprintf(30 * per, 298 * per, "边界色：");
  Rectangle_ color_border(Point(100 * per, 297 * per),
                          Point(114 * per, 311 * per));
  draw(&color_border);
  xyprintf(30 * per, 382 * per, "填充色：");
  Rectangle_ color_fill(Point(100 * per, 381 * per),
                        Point(114 * per, 395 * per));
  draw(&color_fill);
  Rectangle_ color_table(
      Point(w_catalog + 5, h_menu + h_tool + h_shape + h_color_head),
      Point(w_catalog + 5 + wid_colors * 10, 368 * per));
  draw(&color_table);
  setcolor(*temp);
  delete temp;
  temp = nullptr;

  // Point pos_, int wid, int height, Color bor_, Color fil_, Color tex_,
  //    LPCSTR text_, int mode_
  for (int i = 0; i < 4; i++) {
    btn_head.push_back(Button(pos_head[i], wid_head, h_head, Color(), Color(),
                              Color(), t_head[i], 1000 + i));
    btn_head.at(i).show_on_screen();
  }
  for (int i = 0; i < 2; i++) {
    btn_column.push_back(Button(pos_column[i], wid_column, h_column, Color(),
                                Color(), Color(), t_column[i], 2000 + i));
    btn_column.at(i).show_on_screen();
  }
  for (int i = 0; i < 3; i++) {
    btn_steps.push_back(Button(pos_steps[i], wid_steps, h_steps, Color(),
                               Color(), Color(), t_steps[i], 3000 + i));
    btn_steps.at(i).show_on_screen();
  }
  for (int i = 0; i < 6; i++) {
    btn_shapes.push_back(Button(pos_shapes[i], wid_shapes, h_shapes,
                                Color(233, 34, 54), Color(23, 34, 55),
                                Color(233, 34, 55), t_shapes[i], 4000 + i));
    btn_shapes.at(i).show_on_screen();
  }

  for (int i = 0; i < 30; i++) {
    btn_colors.push_back(Button(pos_colors[i / 10][i % 10], wid_colors,
                                h_colors, colors[H1][i / 10][i % 10],
                                colors[H1][i / 10][i % 10],
                                colors[H1][i / 10][i % 10], "", 5000 + i));
    btn_colors.at(i).show_on_screen();
  }
  for (int i = 30; i < 60; i++) {
    btn_colors.push_back(Button(pos_colors[i / 10][i % 10], wid_colors,
                                h_colors, colors[H2][i / 10][i % 10],
                                colors[H2][i / 10][i % 10],
                                colors[H2][i / 10][i % 10], "", 5000 + i));
    btn_colors.at(i).show_on_screen();
  }
  for (int i = 0; i < 20; i++) {
    btn_color_foot.push_back(Button(
        pos_color_foot[i], wid_color_foot, h_color_foot, colors[i % 20][2][5],
        colors[i % 20][2][5], colors[i % 20][2][5], "", 6000 + i));
    btn_color_foot.at(i).show_on_screen();
  }
  for (int i = 20; i < 40; i++) {
    btn_color_foot.push_back(Button(
        pos_color_foot[i], wid_color_foot, h_color_foot, colors[i % 20][2][5],
        colors[i % 20][2][5], colors[i % 20][2][5], "", 6000 + i));
    btn_color_foot.at(i).show_on_screen();
  }
}
void Db::set() {
}
void Db::refresh() {
  for (int i = 0; i < 30; i++) {
    btn_colors.at(i).fill = colors[H1][i/10][i%10];
    btn_colors.at(i).show_on_screen();
  }
  for (int i = 0; i < 30; i++) {
    btn_colors.at(i+30).fill = colors[H2][i / 10][i % 10];
    btn_colors.at(i).show_on_screen();
  }
}
//vector<Button> btn_head;
//vector<Button> btn_column;
//vector<Button> btn_steps;
//vector<Button> btn_tools;
//vector<Button> btn_shapes;
//vector<Button> btn_colors;
//vector<Button> btn_color_foot;
Button& Db::searchButton(mouse_msg m_) {
  for (auto i : btn_head) {
    if (i.ran.is_in_range(Point(m_.x, m_.y))) {
      return i;
    }
  }
  for (auto i : btn_column) {
    if (i.ran.is_in_range(Point(m_.x, m_.y))) {
      return i;
    }
  }
  for (auto i : btn_steps) {
    if (i.ran.is_in_range(Point(m_.x, m_.y))) {
      return i;
    }
  }
  for (auto i : btn_tools) {
    if (i.ran.is_in_range(Point(m_.x, m_.y))) {
      return i;
    }
  }
  for (auto i : btn_shapes) {
    if (i.ran.is_in_range(Point(m_.x, m_.y))) {
      return i;
    }
  }
  for (auto i : btn_colors) {
    if (i.ran.is_in_range(Point(m_.x, m_.y))) {
      return i;
    }
  }
  for (auto i : btn_color_foot) {
    if (i.ran.is_in_range(Point(m_.x, m_.y))) {
      return i;
    }
  }
  return btn_void;
}