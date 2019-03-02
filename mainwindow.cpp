#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <ui_mainwindow.h>
#include <ui_mainwindow.h>

#define MAX_X 800
#define MAX_Y 600

void MainWindow::mousePressEvent(QMouseEvent *event)
{
   // qDebug() << "Event pos" << event->pos();
   // qDebug() << "Global pos" << event->globalPos();
    QTransform transform;
    if (event->x() > MAX_X/2) {
        ui->label_2->setText("<img src = ':/img/img/layToRigth.png' width='115'  height='30'>");
        transform.scale(-0.9, 0.9);
        transform.translate(-100,0);
    }else {
        ui->label_2->setText("<img src = ':/img/img/lay.png' width='115'  height='30'>");
        transform.scale(-0.9, 0.9);
        transform.translate(100,0);
    }
    pixmap->setTransform(transform);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "Event pos" << event->pos();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->
            setStyleSheet("background-color: white;");

    this->setFixedSize(MAX_X+50,MAX_Y+150);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
   // ui->graphicsView->setMouseTracking(true);

    pixmap = new QGraphicsPixmapItem(
                QPixmap(":/img/img/stand.png"));

   // QGraphicsPixmapItem *newItem=new QGraphicsPixmapItem(QPixmap(":/img/img/stand.png"));

    //mouse = new QPixmap(":/img/img/stand.png");
    scene->addItem(pixmap);
    pixmap->setScale(0.33);

    QTransform transform;
        transform.translate(70, -110);
        //transform.rotate(45);
        transform.scale(-0.5, 1.0);
    pixmap->setTransform(transform);
    //pixmap->setRotation(33);

        int half_X = MAX_X/2;
        int half_Y = MAX_Y/2;
        scene->addLine(0,0,half_X,0);
        scene->addLine(0,0,0,half_Y);
        scene->addLine(0,0,-half_X,0);
        scene->addLine(0,0,0,-half_Y);
        scene->addRect(-half_X, -half_Y, MAX_X, MAX_Y,
                       QPen(Qt::DotLine));




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_Rotate_valueChanged(int value)
{
    QString qsTemp = "%1";
        qsTemp = qsTemp.arg(value);
        ui->labelRotate->setText(qsTemp);
        qsTemp = QString::number(value,16);
        qDebug() << " " << qsTemp;
        pixmap->setRotation(value);
}

void MainWindow::on_horizontalSlider_Shear_valueChanged(int value)
{
    QString qsTemp = "%1";
        qsTemp = qsTemp.arg(value);
        ui->labelShear->setText(qsTemp);
        qsTemp = QString::number(value,16);
        qDebug() << " " << qsTemp;
        QTransform transform1;
        transform1.shear(value,-value);
        pixmap->setTransform(transform1);
}
