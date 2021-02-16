#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "openglwidget.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void onAlphaTestChanged(int value);
    void onScissorXChanged(int value);
    void onScissorYChanged(int value);

public:
    static const int SLIDER_MAX;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    OpenGLWidget *openGLWidget;
};
#endif // MAINWINDOW_H
