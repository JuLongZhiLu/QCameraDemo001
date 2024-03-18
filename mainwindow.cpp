#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    const QList<QCameraInfo> availableCameras = QCameraInfo::availableCameras();
    for(auto elem:availableCameras){
        qDebug()<<elem;
    }

    QCameraViewfinder *m_viewFinder = new QCameraViewfinder;

    setCentralWidget(m_viewFinder);

    m_camera = new QCamera(availableCameras[0]);

    m_camera->start();

    m_camera->setViewfinder(m_viewFinder);
}

MainWindow::~MainWindow()
{
    delete ui;
}

