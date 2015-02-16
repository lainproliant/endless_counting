#include <QObject>
#include <QScrollArea>
#include <QKeyEvent>

namespace endless {
   class HexgridScrollArea : public QScrollArea
   {
       Q_OBJECT

   public:
       HexgridScrollArea() : QScrollArea() { }
       ~HexgridScrollArea() { }

   protected:

       void keyPressEvent(QKeyEvent* event) {
           if (event->modifiers() & Qt::ShiftModifier) {
               event->ignore();

           } else {
               QScrollArea::keyPressEvent(event);
           }
       }
   };
}
