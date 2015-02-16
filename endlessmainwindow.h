#ifndef ENDLESSMAINWINDOW_H
#define ENDLESSMAINWINDOW_H

#include <QMainWindow>
#include "hexgridwidget.h"

namespace Ui {
class EndlessMainWindow;
}

class EndlessMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EndlessMainWindow(QWidget *parent = 0);
    ~EndlessMainWindow();

private:
    Ui::EndlessMainWindow *ui;
    endless::HexgridWidget* hexgridWidget;
};

#endif // ENDLESSMAINWINDOW_H
