#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    const QList<QCameraInfo> availableCameras = QCameraInfo::availableCameras();
    for(auto elem : availableCameras){
        qDebug() << elem;
    }

    QCameraViewfinder *m_viewFinder = new QCameraViewfinder;
    m_camera = new QCamera(availableCameras[0]);
    m_camera->setViewfinder(m_viewFinder);

    QPushButton *startBtn = new QPushButton("Start", this); // 创建开始按钮
    QPushButton *stopBtn = new QPushButton("Stop", this);   // 创建停止按钮

    connect(startBtn, &QPushButton::clicked, this, [=](){
        m_camera->start();
    });

    connect(stopBtn, &QPushButton::clicked, this, [=](){
        m_camera->stop();
    });

    QHBoxLayout *hBoxLayout = new QHBoxLayout; // 创建水平布局管理器
    hBoxLayout->addWidget(startBtn);
    hBoxLayout->addWidget(stopBtn);

    QVBoxLayout *vBoxLayout = new QVBoxLayout; // 创建垂直布局管理器
    vBoxLayout->addWidget(m_viewFinder);
    vBoxLayout->addLayout(hBoxLayout);

    QWidget *centralWidget = new QWidget; // 创建中央部件
    centralWidget->setLayout(vBoxLayout); // 将垂直布局管理器设置为中央部件的布局管理器
    setCentralWidget(centralWidget); // 将中央部件设置为主窗口的中央部件
}

MainWindow::~MainWindow()
{
    delete ui;
}
