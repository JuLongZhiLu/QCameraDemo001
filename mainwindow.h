#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QDebug>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QCamera *m_camera;
    QCameraViewfinder *m_viewFinder;
    QPushButton *startBtn;
    QPushButton *stopBtn;
};
#endif // MAINWINDOW_H
