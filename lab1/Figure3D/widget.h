#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QMessageBox>
#include "taskManager.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_LoadFile_clicked();
    void on_Carryover_clicked();
    void on_Scale_clicked();
    void on_Rotate_clicked();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
};

#endif // WIDGET_H
