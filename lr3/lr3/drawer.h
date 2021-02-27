#pragma once

#include <QOpenGLWidget>

class Drawer : public QOpenGLWidget
{
    Q_OBJECT
public:
    Drawer(QWidget *parent = nullptr);

public slots:
    void configChanged();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
};

