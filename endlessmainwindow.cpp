#include "endlessmainwindow.h"
#include "ui_endlessmainwindow.h"
#include "ui_about.h"

#include "hexgridscrollarea.h"
#include "counting_hexgridwidget.h"

#include <QHBoxLayout>
#include <QFileDialog>
#include <QStandardPaths>

EndlessMainWindow::EndlessMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EndlessMainWindow)
{
    ui->setupUi(this);

    hexgridWidget = new endless::MapHexgridWidget(this);
    hexgridWidget->initialize(10, 10);
    QScrollArea* scrollArea = new endless::HexgridScrollArea();
    scrollArea->setWidget(hexgridWidget);

    scrollArea->setFocusPolicy(Qt::StrongFocus);
    hexgridWidget->setFocusPolicy(Qt::StrongFocus);

    statusLabel = new QLabel();
    statusLabel->setFont(QFont("Helvetica", 24));
    statusBar()->addPermanentWidget(statusLabel);

    setCentralWidget(scrollArea);
}

void EndlessMainWindow::openFile() {
    QString filename = QFileDialog::getOpenFileName(
        this, "Open a Grid File", QStandardPaths::writableLocation(QStandardPaths::StandardLocation::HomeLocation),
        "Grid JSON files (*.json)");

    if (! filename.isNull()) {
        endless::MapHexgrid& hexgrid = static_cast<endless::MapHexgrid&>(
            hexgridWidget->get_hexgrid());

        hexgrid.read_from_file(filename.toStdString());
        hexgrid.update();
        emit hexgridWidget->updated();
        hexgridWidget->repaint();
    }
}

void EndlessMainWindow::saveFile() {
    QString filename = QFileDialog::getSaveFileName(
        this, "Save a Grid File", QStandardPaths::writableLocation(QStandardPaths::StandardLocation::HomeLocation),
        "Grid JSON files (*.json)");

    if (! filename.isNull()) {
        endless::MapHexgrid& hexgrid = static_cast<endless::MapHexgrid&>(
            hexgridWidget->get_hexgrid());

        if (! filename.endsWith(".json")) {
            filename += ".json";
        }

        hexgrid.write_to_file(filename.toStdString());
    }
}

void EndlessMainWindow::saveImage() {
    QString filename = QFileDialog::getSaveFileName(
        this, "Save a Grid Snapshot Image", QStandardPaths::writableLocation(QStandardPaths::StandardLocation::HomeLocation),
        "PNG Image Files (*.png)");

    if (! filename.isNull()) {
        endless::MapHexgrid& hexgrid = static_cast<endless::MapHexgrid&>(
            hexgridWidget->get_hexgrid());

        if (! filename.endsWith(".png")) {
            filename += ".png";
        }

        hexgridWidget->clear_focus();
        hexgridWidget->repaint();
        hexgridWidget->grab().save(filename);
    }
}

void EndlessMainWindow::clearMap() {
    endless::MapHexgrid& hexgrid = static_cast<endless::MapHexgrid&>(
        hexgridWidget->get_hexgrid());
    int width = hexgrid.get_width();
    int height = hexgrid.get_height();
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            hexgrid.put(std::make_shared<endless::WaterHex>(QPoint(x, y)));
        }
    }
    hexgrid.update();
    emit hexgridWidget->updated();
    repaint();
}

void EndlessMainWindow::fillMap() {
    endless::MapHexgrid& hexgrid = static_cast<endless::MapHexgrid&>(
        hexgridWidget->get_hexgrid());
    int width = hexgrid.get_width();
    int height = hexgrid.get_height();
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::shared_ptr<endless::MapHex> hex = hexgrid.get<endless::MapHex>(x, y);
            if (hex == nullptr || hex->get_type() == endless::MapHex::Type::WATER) {
                hexgrid.put(std::make_shared<endless::GroundHex>(QPoint(x, y)));
            }
        }
    }
    hexgrid.update();
    emit hexgridWidget->updated();
    repaint();
}

void EndlessMainWindow::updateStatus() {
    endless::MapHexgrid& hexgrid = static_cast<endless::MapHexgrid&>(
        hexgridWidget->get_hexgrid());

    statusLabel->setText(QString().sprintf("District Score: %d, Coverage: %d",
        hexgrid.get_district_score(), hexgrid.get_coverage()));
}

void EndlessMainWindow::about() {
    QDialog* dialog = new QDialog(this);

    Ui::AboutDialog aboutUi;
    aboutUi.setupUi(dialog);

    dialog->show();
}

EndlessMainWindow::~EndlessMainWindow()
{
    delete ui;
}
