#pragma once
#include <map>

#include "hex.h"
#include "hexgridwidget.h"

namespace endless {
   using namespace std;

   const int DISTRICT_MAX_LEVEL = 3;
   const int DISTRICT_IMPROVEMENT_THRESHOLD = 4;
   const QPen NORMAL_EDGE_PEN = QPen(QBrush(Qt::black), 3.0);
   const QPen FOCUSED_EDGE_PEN = QPen(QBrush(Qt::blue), 6.0);
   const QPen DISTRICT_EDGE_PEN = QPen(QBrush(Qt::red), 3.0);
   const QBrush HEX_BRUSH = QBrush(Qt::white);
   const QFont DISTRICT_COUNT_FONT = QFont("Helvetica", 20);

   class MapHex : public Hex {
   public:
       enum Type {
           DISTRICT,
           WATER,
           EMPTY
       };

       MapHex(Type hex_type, const QPoint& pt) :
           Hex(pt), hex_type(hex_type) { }

       Type get_type() const {
           return hex_type;
       }

       virtual void render(QPainter& painter, const Hexgrid& hexgrid,
                           double radius, bool focused) const = 0;

   private:
       Type hex_type;
   };

   class EmptyHex : public MapHex {
   public:
       EmptyHex(const QPoint& pt) :
           MapHex(MapHex::Type::EMPTY, pt) { }

       virtual void render(QPainter& painter, const Hexgrid& hexgrid,
                           double radius, bool focused) const override {
           QPainterPath path;
           path.addPolygon(get_polygon(radius));
           painter.fillPath(path, HEX_BRUSH);
           const QPen& pen = focused ? FOCUSED_EDGE_PEN : NORMAL_EDGE_PEN;
           painter.setPen(pen);
           painter.drawPolygon(get_polygon(radius));
       }
   };

   class DistrictHex : public MapHex {
   public:
       DistrictHex(const QPoint& pt) : MapHex(MapHex::Type::DISTRICT, pt) { }
       int get_level() const {
           return level;
       }

       void set_level(int level) {
           this->level = level;
       }

       void render(QPainter& painter, const Hexgrid& hexgrid,
                   double radius, bool focused) const override {
           const QPen& pen = focused ? FOCUSED_EDGE_PEN : DISTRICT_EDGE_PEN;
           QPainterPath path;
           path.addPolygon(get_polygon(radius));
           painter.fillPath(path, HEX_BRUSH);
           painter.setPen(pen);
           painter.drawPolygon(get_polygon(radius));
           painter.setFont(DISTRICT_COUNT_FONT);
           painter.drawText(get_center(radius).toPoint(), QString().sprintf("%d", get_level()));
       }

   private:
       int level = 1;
   };

   class WaterHex : public MapHex {
   public:
       WaterHex(const QPoint& pt) : MapHex(MapHex::Type::WATER, pt) { }
       void render(QPainter& painter, const Hexgrid& hexgrid,
                   double radius, bool focused) const override {
           const QPen& pen = focused ? FOCUSED_EDGE_PEN : NORMAL_EDGE_PEN;
           painter.setPen(pen);
           painter.drawPolygon(get_polygon(radius));
       }
   };

   class MapHexgrid : public Hexgrid {
   public:
       MapHexgrid() : Hexgrid() { }

       void update() {
           calculate_district_levels();
       }

   protected:
       virtual shared_ptr<Hex> create_hex(int x, int y) override {
           return make_shared<EmptyHex>(QPoint(x, y));
       }

   private:
       void calculate_district_levels(int n = 1) {
           if (n == 1) {
               reset_district_levels();
           }

           vector<shared_ptr<DistrictHex>> level_up_hexes;

           for (int x = 0; x < get_width(); x++) {
               for (int y = 0; y < get_height(); y++) {
                   shared_ptr<DistrictHex> hex = get<DistrictHex>(x, y);
                   if (hex == nullptr) {
                       continue;
                   }

                   vector<shared_ptr<DistrictHex>> adj_hexes = get_adjacent_of_type<DistrictHex>(x, y);
                   int total = 0;
                   for (auto adj_hex : adj_hexes) {
                       if (adj_hex->get_level() >= n - 1) {
                           total++;
                       }
                   }

                   if (total >= DISTRICT_IMPROVEMENT_THRESHOLD) {
                       level_up_hexes.push_back(hex);
                   }
               }
           }

           for (auto hex : level_up_hexes) {
               hex->set_level(n);
           }

           if (n < DISTRICT_MAX_LEVEL) {
               calculate_district_levels(n + 1);
           }
       }

       void reset_district_levels() {
           for (int x = 0; x < get_width(); x++) {
               for (int y = 0; y < get_height(); y++) {
                   shared_ptr<DistrictHex> hex = get<DistrictHex>(x, y);
                   if (hex) {
                       hex->set_level(1);
                   }
               }
           }
       }
   };
}

