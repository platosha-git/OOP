#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <memory>
#include "drawlabel.h"
#include "draw/qt_drawer.hpp"
#include "facade/facade_viewer.hpp"
#include "commands/command.h"
#include "commands/addModelCom.h"
#include "commands/addCameraCom.h"
#include "commands/setCameraCom.h"
#include "commands/renderCom.h"
#include "commands/transformModelCom.h"
#include "commands/transformCameraCom.h"
#include "commands/removeCameraCom.h"
#include "commands/removeModelCom.h"
#include "exceptions/exceptions.h"
#include "draw/qtgraphfactory.h"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_addModel_clicked();

    void on_pushButton_addCamera_clicked();

    void on_pushButton_setCamera_clicked();

    void on_pushButton_moveModel_clicked();

    void on_pushButton_scaleModel_clicked();

    void on_pushButton_rotateModel_clicked();

    void on_pushButton_moveCamera_clicked();

    void on_pushButton_rotateCamera_clicked();

    void on_pushButton_removeCamera_clicked();

    void on_pushButton_removeModel_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap pixmap;
    std::unique_ptr<FacadeViewer> facade_viewer;
    size_t index_model;
    size_t index_camera;

    std::string development_environment;
    void render();
    std::string readConfigFile();
};
#endif // MAINWINDOW_H
