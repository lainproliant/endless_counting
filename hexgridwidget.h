#pragma once
#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>

#include <cmath>
#include <iostream>
#include <memory>

#include "hex.h"

#define HEXGRID_MAX_WIDTH 30
#define HEXGRID_MAX_HEIGHT 30

namespace endless {
   using namespace std;

   class HexgridWidget : public QWidget
   {
       Q_OBJECT

   signals:
       void updated();

   public:
       explicit HexgridWidget(QWidget *parent = 0) :
           QWidget(parent) {

           setFocusPolicy(Qt::FocusPolicy::StrongFocus);
           setBackgroundRole(QPalette::Light);
           setMouseTracking(true);
       }

       void initialize(int width, int height) {
           hexgrid = create_hexgrid();
           hexgrid->initialize(width, height);
           adjust_size();
       }
      
       template<class T>
       shared_ptr<T> get_focused_hex() const {
           return has_focused_hex() ? hexgrid->get<T>(focused_hex.x(), focused_hex.y()) : nullptr;
       }

       bool has_focused_hex() const {
           return focused_hex.x() >= 0 && focused_hex.x() < hexgrid->get_width() &&
                  focused_hex.y() >= 0 && focused_hex.y() < hexgrid->get_height();
       }

       void clear_focus() {
           focused_hex = QPoint(-1, -1);
       }

       Hexgrid& get_hexgrid() {
           return *hexgrid;
       }

       double get_hex_radius() const {
           return hex_radius;
       }

       void set_hex_radius(double radius) {
           hex_radius = radius;
           adjust_size();
       }

       virtual ~HexgridWidget() { }

   protected:
       virtual shared_ptr<Hexgrid> create_hexgrid() = 0;
       virtual void paint_hex(QPainter& painter, shared_ptr<Hex> hex) = 0;

       virtual void paintEvent(QPaintEvent* event) {
           QPainter painter(this);

           for (int y = 0; y < hexgrid->get_height(); y++) {
               for (int x = 0; x < hexgrid->get_width(); x++) {
                   paint_hex(painter, hexgrid->get<Hex>(x, y));
               }
           }
       }

       virtual void keyPressEvent(QKeyEvent* event) {
          if (event->key() == Qt::Key_Left && event->modifiers() & Qt::ShiftModifier &&
              hexgrid->get_width() > 0) {
              hexgrid->dimension_grid(hexgrid->get_width() - 1, hexgrid->get_height());
              adjust_size();

          } else if (event->key() == Qt::Key_Right && event->modifiers() & Qt::ShiftModifier &&
              hexgrid->get_width() < HEXGRID_MAX_WIDTH) {
              hexgrid->dimension_grid(hexgrid->get_width() + 1, hexgrid->get_height());
              adjust_size();

          } else if (event->key() == Qt::Key_Down && event->modifiers() & Qt::ShiftModifier &&
              hexgrid->get_height() < HEXGRID_MAX_HEIGHT) {
              hexgrid->dimension_grid(hexgrid->get_width(), hexgrid->get_height() + 1);
              adjust_size();

          } else if (event->key() == Qt::Key_Up && event->modifiers() & Qt::ShiftModifier &&
              hexgrid->get_height() > 0) {
              hexgrid->dimension_grid(hexgrid->get_width(), hexgrid->get_height() - 1);
              adjust_size();

          } else {
              QWidget::keyPressEvent(event);
          }
       }

       QPoint calculate_focused_hex(QMouseEvent* event) {
           int x = event->x(), y = event->y(), x_adj = 0.0;
           double grid_box_width =  2 * hex_radius * HEX_WIDTH_RATIO;
           double grid_box_height = 1.5 * hex_radius;
           int hex_x, hex_y;

           // Determine if we are in an odd row.
           if (fmod(y / grid_box_height, 2.0) >= 1.0) {
               x_adj = HEX_WIDTH_RATIO * hex_radius;
           }

           hex_x = (x - x_adj) / grid_box_width;
           hex_y = y / grid_box_height;

           if (hex_x >= 0 && hex_x < hexgrid->get_width() &&
               hex_y >= 0 && hex_y < hexgrid->get_height()) {

              if (! (hex_x == focused_hex.x() && hex_y == focused_hex.y())) {
                 return QPoint(hex_x, hex_y);
              }
           }

           return focused_hex;
       }

       virtual void mouseMoveEvent(QMouseEvent* event) {
           QPoint new_hex = calculate_focused_hex(event);
           if (new_hex != focused_hex &&
               new_hex.x() >= 0 && new_hex.x() < hexgrid->get_width() &&
               new_hex.y() >= 0 && new_hex.y() < hexgrid->get_height()) {
               focused_hex = new_hex;
               repaint();
           }
       }

       QSize sizeHint() const {
           int width = 2 * hex_radius * HEX_WIDTH_RATIO * hexgrid->get_width() + hex_radius;
           int height = HEX_HEIGHT_RATIO * hex_radius * hexgrid->get_height() + hex_radius / 2;
           return QSize(width, height);
       }

       void adjust_size() {
           resize(sizeHint());
       }

   private:
       double hex_radius = 50.0;

       QPoint focused_hex = QPoint(-1, -1);
       shared_ptr<Hexgrid> hexgrid;
   };
}
