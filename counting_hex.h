#pragma once
#include <map>
#include <set>

#include "hex.h"
#include "hexgridwidget.h"
#include "settings.h"

namespace endless {
   using namespace std;

   const int DISTRICT_MAX_LEVEL = 3;
   const int DISTRICT_IMPROVEMENT_THRESHOLD = 4;
   const QPen NORMAL_EDGE_PEN = QPen(QBrush(Qt::black), 3.0);
   const QPen FOCUSED_EDGE_PEN = QPen(QBrush(Qt::blue), 6.0);
   const QBrush HEX_BRUSH = QBrush(Qt::white);

   const QPen DISTRICT_COUNT_PEN = QPen(QBrush(Qt::white), 1.0);
   const QFont DISTRICT_COUNT_FONT = QFont("Helvetica", 20);

   const QBrush DISTRICT_BRUSHES[] = {
       QBrush(QColor::fromRgb(0xFFEDA2)),
       QBrush(QColor::fromRgb(0xD4994F)),
       QBrush(QColor::fromRgb(0xAB0404)),
       QBrush(QColor::fromRgb(0xB20464))
   };

   class MapHex : public Hex {
   public:
       enum Type {
           WATER = 0,
           GROUND = 1,
           DISTRICT = 2
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

   class GroundHex : public MapHex {
   public:
       GroundHex(const QPoint& pt) :
           MapHex(MapHex::Type::GROUND, pt) { }

       virtual void render(QPainter& painter, const Hexgrid& hexgrid,
                           double radius, bool focused) const override {
           QPainterPath path;
           painter.setBrush(DISTRICT_BRUSHES[0]);
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
           const QPen& pen = focused ? FOCUSED_EDGE_PEN : NORMAL_EDGE_PEN;
           QPainterPath path;
           path.addPolygon(get_polygon(radius));
           painter.setBrush(DISTRICT_BRUSHES[level]);
           painter.fillPath(path, HEX_BRUSH);
           painter.setPen(pen);
           painter.drawPolygon(get_polygon(radius));
           painter.setPen(DISTRICT_COUNT_PEN);
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
           painter.setBrush(Qt::NoBrush);
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

       int get_coverage() const {
           return coverage;
       }

       int get_district_score() const {
           return district_score;
       }

       void read_from_file(const string& filename) {
           Settings settings = Settings::load_from_file(filename);

           int width = settings.get<int>("width");
           int height = settings.get<int>("height");
           vector<int> flat_table = settings.get_array<int>("flat_table");

           if (flat_table.size() != width * height) {
               throw runtime_error("flat_table is the wrong size.");
           }

           dimension_grid(width, height);

           for (int y = 0; y < height; y++) {
               for (int x = 0; x < width; x++) {
                   int type_code = flat_table[y * width + x];
                   shared_ptr<MapHex> hex;

                   switch (type_code) {
                   case MapHex::Type::WATER:
                       hex = make_shared<WaterHex>(QPoint(x, y));
                       break;

                   case MapHex::Type::DISTRICT:
                       hex = make_shared<DistrictHex>(QPoint(x, y));
                       break;

                   default:
                       hex = make_shared<GroundHex>(QPoint(x, y));
                       break;
                   }

                   put(hex);
               }
           }
       }

       void write_to_file(const string& filename) {
           Settings settings;
           settings.set<int>("width", get_width());
           settings.set<int>("height", get_height());

           vector<int> flat_table;
           for (int y = 0; y < get_height(); y++) {
              for (int x = 0; x < get_width(); x++) {
                  shared_ptr<MapHex> hex = get<MapHex>(x, y);
                  flat_table.push_back(hex ? hex->get_type() : MapHex::Type::WATER);
              }
           }

           settings.set_array<int>("flat_table", flat_table);
           settings.save_to_file(filename);
       }

   protected:
       virtual shared_ptr<Hex> create_hex(int x, int y) override {
           return make_shared<WaterHex>(QPoint(x, y));
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

           } else {
               calculate_coverage();
               calculate_district_score();
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

       void calculate_coverage() {
           set<QString> covered_points;

           auto ptrepr = [](const QPoint& pt) -> QString {
               return QString().sprintf("%d,%d",
                   pt.x(), pt.y());
           };

           for (int y = 0; y < get_height(); y++) {
               for (int x = 0; x < get_width(); x++) {
                   shared_ptr<DistrictHex> district_hex = get<DistrictHex>(x, y);

                   if (district_hex != nullptr) {
                       covered_points.insert(ptrepr(district_hex->get_point()));

                       for (QPoint pt : district_hex->get_adjacent()) {
                           shared_ptr<MapHex> hex = get<MapHex>(pt);
                           if (hex != nullptr && hex->get_type() != MapHex::Type::WATER) {
                               covered_points.insert(ptrepr(pt));
                           }
                       }
                   }
               }
           }

           coverage = covered_points.size();
       }

       void calculate_district_score() {
           int total = 0;
           for (int y = 0; y < get_height(); y++) {
               for (int x = 0; x < get_width(); x++) {
                   shared_ptr<DistrictHex> hex = get<DistrictHex>(x, y);
                   if (hex != nullptr) {
                      total += hex->get_level();
                   }
               }
           }

           district_score = total;
       }

   private:
       int coverage = 0;
       int district_score = 0;
   };
}

