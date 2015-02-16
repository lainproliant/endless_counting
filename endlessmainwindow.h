#ifndef ENDLESSMAINWINDOW_H
#define ENDLESSMAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
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

public slots:
    void openFile();
    void saveFile();
    void clearMap();
    void fillMap();
    void saveImage();
    void updateStatus();
    void about();

private:
    Ui::EndlessMainWindow *ui;
    endless::HexgridWidget* hexgridWidget;
    QLabel* statusLabel;
};

#endif // ENDLESSMAINWINDOW_H
