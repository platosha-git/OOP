#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
}

Widget::~Widget()
{
    delete ui;

    ArgsManager args;
    LoadArgsToDeleteFigure(args);
    TaskManager(fdelete, args);
}

void Widget::on_LoadFile_clicked()
{
    //Преобразование Qsting в const char*
    QString qfname = QFileDialog::getOpenFileName(nullptr, "Выберите файл", "", "*.txt");
    std::string sname = qfname.toStdString();
    const char *fname = sname.c_str();

    ArgsManager args;
    LoadArgsToLoadFigure(args, fname);

    TError exitCode = TaskManager(load, args);
    if (exitCode == SUCCESS) {
        LoadArgsToDrawFigure(args, ui->graphicsView->scene());
        exitCode = TaskManager(draw, args);
    }

    if (exitCode != SUCCESS) {
        QMessageBox::warning(this, "Ошибка", "Загрузка не корректна!");
    }
}

void Widget::on_Carryover_clicked()
{
    QString qdx = ui->dxCarry->text();
    QString qdy = ui->dyCarry->text();
    QString qdz = ui->dzCarry->text();

    ArgsManager args;
    TError exitCode = LoadArgsToMoveFigure(args, qdx, qdy, qdz);
    if (exitCode == SUCCESS) {
        exitCode = TaskManager(carry, args);
        if (exitCode == SUCCESS) {
            LoadArgsToDrawFigure(args, ui->graphicsView->scene());
            exitCode = TaskManager(draw, args);
        }
    }

    if (exitCode != SUCCESS) {
        QMessageBox::warning(this, "Ошибка", "Коэффициенты переноса не корректны!");
    }
}

void Widget::on_Scale_clicked()
{
    QString kx = ui->kxScale->text();
    QString ky = ui->kyScale->text();
    QString kz = ui->kzScale->text();
    QString x = ui->xScale->text();
    QString y = ui->yScale->text();
    QString z = ui->zScale->text();

    struct ArgsManager args;
    TError exitCode = LoadArgsToScaleFigure(args, kx, ky, kz, x, y, z);
    if (exitCode == SUCCESS) {
        exitCode = TaskManager(scale, args);
        if (exitCode == SUCCESS) {
            LoadArgsToDrawFigure(args, ui->graphicsView->scene());
            exitCode = TaskManager(draw, args);
        }
    }

    if (exitCode != SUCCESS) {
        QMessageBox::warning(this, "Ошибка", "Коэффициенты масштабирования не корректны!");
    }
}

void Widget::on_Rotate_clicked()
{
    QString angle = ui->angleRotate->text();
    QString x = ui->xRotate->text();
    QString y = ui->yRotate->text();
    QString z = ui->zRotate->text();

    struct ArgsManager args;
    TError exitCode = LoadArgsToRotateFigure(args, angle, x, y, z);
    if (exitCode == SUCCESS) {
        exitCode = TaskManager(rotate, args);
        if (exitCode == SUCCESS) {
            LoadArgsToDrawFigure(args, ui->graphicsView->scene());
            exitCode = TaskManager(draw, args);
        }
    }

    if (exitCode != SUCCESS) {
        QMessageBox::warning(this, "Ошибка", "Коэффициенты поворота не корректны!");
    }
}
