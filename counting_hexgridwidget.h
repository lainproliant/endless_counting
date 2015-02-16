#pragma once

#include "hex.h"
#include "counting_hex.h"

namespace endless {
   using namespace std;

   const QImage WATER_IMAGE = QImage(":/images/water.png");
   const QBrush WATER_BRUSH = QBrush(WATER_IMAGE);

   class MapHexgridWidget : public HexgridWidget {
      Q_OBJECT

   protected:
       virtual shared_ptr<Hexgrid> create_hexgrid() override {
           return make_shared<MapHexgrid>();
       }

       virtual void paintEvent(QPaintEvent* event) {
           QPainter painter(this);

           painter.fillRect(QRect(QPoint(0, 0), size()), WATER_BRUSH);

           for (int y = 0; y < get_hexgrid().get_height(); y++) {
               for (int x = 0; x < get_hexgrid().get_width(); x++) {
                   paint_hex(painter, get_hexgrid().get<Hex>(x, y));
               }
           }
       }

       virtual void paint_hex(QPainter& painter, shared_ptr<Hex> hex) override {
           shared_ptr<MapHex> map_hex = dynamic_pointer_cast<MapHex>(hex);
           if (map_hex == nullptr) {
               throw runtime_error(string("Hexgrid contains non-MapHex: ") + typeid(*hex).name());
           }
           map_hex->render(painter, get_hexgrid(), get_hex_radius(),
                           get_focused_hex<Hex>() != nullptr &&
                           get_focused_hex<Hex>()->get_point() == hex->get_point());
       }

       void mousePressEvent(QMouseEvent* event) {
           shared_ptr<MapHex> hex = get_focused_hex<MapHex>();

           if (hex == nullptr) {
               return;
           }

           switch (event->button()) {
           case Qt::LeftButton:
               if (hex->get_type() == MapHex::Type::EMPTY) {
                   get_hexgrid().put(make_shared<DistrictHex>(hex->get_point()));

               } else if (hex->get_type() == MapHex::Type::WATER) {
                   get_hexgrid().put(make_shared<EmptyHex>(hex->get_point()));
               }
               break;

           case Qt::RightButton:
               if (hex->get_type() == MapHex::Type::DISTRICT) {
                   get_hexgrid().put(make_shared<EmptyHex>(hex->get_point()));

               } else if (hex->get_type() == MapHex::Type::EMPTY) {
                   get_hexgrid().put(make_shared<WaterHex>(hex->get_point()));
               }
               break;
           }

           get_hexgrid().update();
           repaint();
       }
   };
}
