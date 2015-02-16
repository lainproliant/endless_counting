#include "endlessmainwindow.h"
#include "ui_endlessmainwindow.h"

#include "hexgridscrollarea.h"
#include "counting_hexgridwidget.h"

#include <QHBoxLayout>

EndlessMainWindow::EndlessMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EndlessMainWindow)
{
    ui->setupUi(this);

    hexgridWidget = new endless::MapHexgridWidget();
    hexgridWidget->initialize(10, 10);
    QScrollArea* scrollArea = new endless::HexgridScrollArea();
    scrollArea->setWidget(hexgridWidget);

    scrollArea->setFocusPolicy(Qt::StrongFocus);
    hexgridWidget->setFocusPolicy(Qt::StrongFocus);

    setCentralWidget(scrollArea);
}

EndlessMainWindow::~EndlessMainWindow()
{
    delete ui;
}
