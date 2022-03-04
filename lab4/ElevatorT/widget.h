#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "lift.h"

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
    void on_inFloor1_clicked();
    void on_inFloor2_clicked();
    void on_inFloor3_clicked();
    void on_inFloor4_clicked();
    void on_inFloor5_clicked();

    void on_outFloor1_clicked();
    void on_outFloor2_clicked();
    void on_outFloor3_clicked();
    void on_outFloor4_clicked();
    void on_outFloor5_clicked();

private:
    Ui::Widget *ui;
    Lift lift;
};

#endif // WIDGET_H
