#include"controller.h"
#include"interface.h"
#include<cmath>
//class Controller {
// public:
//  Controller();
//  void table_start();
//  void init_gra();
//  void run();
//  void close_gra();
//};

Controller::Controller() {}
void Controller::table_start() {}
void Controller::run_gra() {
  initgraph(-1, -1, 0x1);
  ege_enable_aa(true);
  setbkcolor(WHITE);

  Db db;
  db.get_screen();
  xyprintf(300, 300, "%d,%d", db.screen_right, db.screen_bottom);
  Button btn_temp;
  mouse_msg mouse = getmouse();
  key_msg key = key_msg();
  key.key = '0';
  int is_left = 0;
  Color color_border = Color();
  Color color_fill = Color();

  Shape* p_shape = nullptr;
  Line* line_ =new Line(Point(), Point());
  Arc_* arc_ = new Arc_(Point(), 100000, 100000, 100000);
  Circle* cir_ = new Circle(Point(), 0);
  stack<Point> poly_po;
  poly_po.push(Point());
  Point rec_po[2];
  int n_po{0};
  Rectangle_* rec_ = new Rectangle_(Point(), Point());
  Triangle* tri_ = new Triangle(Point(),Point(),Point());
  Point tri_po[3];
  Point po_temp{};
  bool po_temp_flag = 0;

  int mod = 0;
  int mod_shape = 0;


  setcolor(GREEN);
  for (int i=0; ;i++) {
    mouse = getmouse();
    xyprintf(700, 100, "%d,%d     ", mouse.is_left(), mouse.is_move());
    is_left += mouse.is_left();
    is_left %= 2;
    if (is_left&&!mouse.is_move()) {
      btn_temp = db.searchButton(mouse);
      mod = btn_temp.mode;
      if (mod >= 1000 && mod < 2000) {
        if (1003 == mod) {
          break;
        }
      } else if (mod >= 2000 && mod < 3000) {

      } else if (mod >= 3000 && mod < 4000) {
      } else if (mod >= 4000 && mod < 5000) {
        mod_shape = mod + 1 - 4000;
      } else if (mod >= 5000 && mod < 6000) {
        if (mod < 5030) {
          color_border = btn_temp.fill;
          xyprintf(800, 100, "bor,%d",i);
        } else {
          color_fill = btn_temp.fill;
        }
      } else if (mod >= 6000 && mod < 7000) {
        if (mod < 6020) {
          db.H1 = mod - 6000;
        } else {
          db.H2 = mod - 6020;
        }
        db.refresh();
      } else if (404 == mod) {
        if (mouse.x > db.w_menu) {
          po_temp_flag = 1;
          po_temp = Point(mouse.x, mouse.y);
        }
      }
    }


    if (1 == mod_shape) {
      if (0 == line_->getCoo1().getX()) {
        if (1 == po_temp_flag) {
          line_->setCoo1(po_temp);
          po_temp_flag = 0;
        }
      } else if (0 == line_->getCoo2().getX()) {
        if (1 == po_temp_flag) {
          line_->setCoo2(po_temp);
          line_->setBorder(color_border);
          po_temp_flag = 0;
          draw(line_);
          line_->setCoo1(Point());
          line_->setCoo2(Point());
        }
      }
    } else if (2 == mod_shape) {
      if (Point() ==arc_->getCenter()) {
        if (1 == po_temp_flag) {
          arc_->setCenter(po_temp);
          po_temp_flag = 0;
        }
      } else if (100000==arc_->getSt()) {
        if (1 == po_temp_flag) {
          arc_->setSt(int(
              float(atan(float(po_temp.getY() - arc_->getCenter().getY()) /
                         float(po_temp.getX() - arc_->getCenter().getX()))) /
                  float(3.1415926) * 180) +
              (po_temp.getX() - arc_->getCenter().getX() >= 0 ? 0 : 180));
          arc_->setRadius(int(pow((pow((po_temp.getY() - arc_->getCenter().getY()), 2) +
                          pow((po_temp.getX() - arc_->getCenter().getX()), 2)),0.5)));
          po_temp_flag = 0;
        }
      } else if (100000 == arc_->getEnd()) {
        if (1 == po_temp_flag) {
          arc_->setEnd(int(
              float(atan(float(po_temp.getY() - arc_->getCenter().getY()) /
                         float(po_temp.getX() - arc_->getCenter().getX()))) /
                  float(3.1415926) * 180) +
              (po_temp.getX() - arc_->getCenter().getX()>=0?0:180));
          po_temp_flag = 0;
          draw(arc_);
          *arc_ = Arc_(Point(), 100000, 100000, 100000);
        }
      }
    } else if (3 == mod_shape) {
      if (Point()== cir_->getCen()) {
        if (1 == po_temp_flag) {
          cir_->setCen(po_temp);
          po_temp_flag = 0;
        }
      } else if (0 == cir_->getRadius()) {
        if (1 == po_temp_flag) {
          cir_->setRadius(
              int(pow((pow((po_temp.getY() - cir_->getCen().getY()), 2) +
                       pow((po_temp.getX() - cir_->getCen().getX()), 2)),
                      0.5)));
          cir_->setRadius_b(cir_->getRadius());
          po_temp_flag = 0;
          draw(cir_);
          *cir_ = Circle(Point(), 0);
        }
      }
    } else if (4 == mod_shape) {
      if (0 == n_po) {
        for (; !poly_po.empty();) {
          poly_po.pop();
        }
        n_po = key.key-48;
        xyprintf(500, 500, "%d", n_po);
      }
      if (poly_po.size() < n_po) {
        if (1 == po_temp_flag) {
          poly_po.push(po_temp);
          po_temp_flag = 0;
        }
      } else {
        Polygon_ p_{Polygon_(poly_po)};
        draw(&p_);
        n_po = 0;
        for (; !poly_po.empty();) {
          poly_po.pop();
        }
        poly_po.push(Point());
      }

    } else if (5 == mod_shape) {
      if (Point() ==rec_po[0]) {
        if (1 == po_temp_flag) {
          rec_po[0] = po_temp;
          po_temp_flag = 0;
        }
      } else if (Point()== rec_po[1]) {
        if (1 == po_temp_flag) {
          rec_po[1] = po_temp;
          *rec_ = Rectangle_(rec_po[0],rec_po[1]);
          po_temp_flag = 0;
          draw(rec_);
          rec_po[0] = Point();
          rec_po[1] = Point();
        }
      }
    } else if (6 == mod_shape) {
      if (Point() == tri_po[0]) {
        if (po_temp_flag) {
          tri_po[0] = po_temp;
          po_temp_flag = 0;
        }
      } else if (Point() == tri_po[1]) {
        if (po_temp_flag) {
          tri_po[1] = po_temp;
          po_temp_flag = 0;
        }
      } else if (Point() == tri_po[2]) {
        if (po_temp_flag) {
          tri_po[2] = po_temp;
          po_temp_flag = 0;
          tri_->setEndpoints(tri_po[0], tri_po[1], tri_po[2]);
          draw(tri_);
          for (int i = 0; i < 3; i++) {
            tri_po[i] = Point();
          }
        }
      }
    }





    if (nullptr != p_shape) {
      draw(p_shape);
    }
    xyprintf(300, 350, "%d,%d", mouse.x, mouse.y);
    xyprintf(300, 400, "%d", mod);
    //xyprintf(300, 500, "shape:%s", );
    db.set();
  }




  ege::closegraph();
}




const int wid_colu1 = 30, height_colu1 = 60;
const Color color_button_fill{23, 44, 234};
const Color color_button_border{255, 255, 255};
const Color color_button_text{221, 234, 222};