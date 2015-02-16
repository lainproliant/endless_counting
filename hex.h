#pragma once
#include <vector>
#include <memory>
#include <cmath>

#include <QPoint>
#include <QPolygon>
#include <QVector>

namespace endless {
   using namespace std;

   const double HEX_WIDTH_RATIO = cos(M_PI / 6.0);
   const double HEX_HEIGHT_RATIO = 1.5;

   class Hex {
   public:
       Hex(const QPoint& pt) : pt(pt) { }
       virtual ~Hex() { }

       QVector<QPoint> get_adjacent() const {
           if (pt.y() % 2) {
              return {
                  QPoint(pt.x(), pt.y() - 1),
                  QPoint(pt.x() - 1, pt.y()),
                  QPoint(pt.x(), pt.y() + 1),
                  QPoint(pt.x() + 1, pt.y() + 1),
                  QPoint(pt.x() + 1, pt.y()),
                  QPoint(pt.x() + 1, pt.y() - 1)
              };
           } else {
              return {
                  QPoint(pt.x() - 1, pt.y() - 1),
                  QPoint(pt.x() - 1, pt.y()),
                  QPoint(pt.x() - 1, pt.y() + 1),
                  QPoint(pt.x(), pt.y() + 1),
                  QPoint(pt.x() + 1, pt.y()),
                  QPoint(pt.x(), pt.y() - 1)
              };
           }
       }

       QPointF get_center(double hex_radius) const {
           double width = 2 * hex_radius * HEX_WIDTH_RATIO;
           double height = 2 * hex_radius;
           double x_adj = width / 2 + (pt.y() % 2 ? hex_radius * HEX_WIDTH_RATIO : 0.0);

           return QPointF(pt.x() * width + x_adj,
                          pt.y() * hex_radius * HEX_HEIGHT_RATIO + hex_radius);
       }

       QPolygonF get_polygon(double hex_radius) const {
           QPolygonF polygon;
           QPointF center = get_center(hex_radius);
           double rotation = M_PI / 2;

           for (int i = 0; i < 6; i++) {
               polygon << center + QPointF(cos(i * (M_PI / 3) + rotation) * hex_radius,
                                           sin(i * (M_PI / 3) + rotation) * hex_radius);
           }

           return polygon;
       }

       const QPoint& get_point() const {
           return pt;
       }

   private:
       const QPoint pt;
   };

   class Hexgrid {
   public:
       Hexgrid() { }

       virtual void initialize(int width, int height) {
           dimension_grid(width, height);
       }

       virtual ~Hexgrid() { }

       virtual void update() { }

       virtual void dimension_grid(int new_width, int new_height) {
           grid.resize(new_height);

           for (int y = 0; y < new_height; y++) {
               if (new_width < grid[y].size()) {
                  grid[y].resize(new_width);

               } else {
                   for (int x = grid[y].size(); x < new_width; x++) {
                       grid[y].push_back(create_hex(x, y));
                   }
               }
           }

           width = new_width;
           height = new_height;
       }

       int get_width() const {
           return width;
       }

       int get_height() const {
           return height;
       }

       template <class T>
       shared_ptr<T> get(const QPoint& pt) const {
           return get<T>(pt.x(), pt.y());
       }

       template <class T>
       shared_ptr<T> get(int x, int y) const {
           if (x < 0 || x >= width || y < 0 || y >= height) {
               return nullptr;
           }

           shared_ptr<T> p = dynamic_pointer_cast<T>(grid.at(y).at(x));
           return p;
       }

       void put(shared_ptr<Hex> hex) {
           int x = hex->get_point().x();
           int y = hex->get_point().y();

           if (x < 0 || x >= width || y < 0 || y >= height) {
               throw runtime_error("Invalid hex coordinate.");
           }

           grid.at(y).at(x) = hex;
       }

       template <class T>
       vector<shared_ptr<T>> get_adjacent_of_type(int x, int y) {
           vector<shared_ptr<T>> hexes;
           shared_ptr<Hex> hex = get<Hex>(x, y);
           QVector<QPoint> hex_pts = hex->get_adjacent();

           for (auto pt : hex_pts) {
               shared_ptr<T> typed_hex = get<T>(pt.x(), pt.y());
               if (typed_hex) {
                   hexes.push_back(typed_hex);
               }
           }

           return hexes;
       }

   protected:
       virtual shared_ptr<Hex> create_hex(int x, int y) {
           return make_shared<Hex>(QPoint(x, y));
       }

   private:
       int width, height;

       vector<vector<shared_ptr<Hex>>> grid;
   };
}
