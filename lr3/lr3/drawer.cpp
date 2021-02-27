#include "drawer.h"

#include <config.h>

Drawer::Drawer(QWidget *parent) : QOpenGLWidget(parent)
{
    QObject::connect(Config::instance, SIGNAL(changed()), this, SLOT(configChanged()));
}

void Drawer::initializeGL() {
    // TODO set up viewport
}

void Drawer::resizeGL(int w, int h) {
    // TODO set up viewport
}

void Drawer::paintGL() {
    // TODO paint points & lines
}

void Drawer::configChanged() {
    update();
}

void Drawer::mouseMoveEvent(QMouseEvent* event) {
    Config::instance->onMouseMove(event);
}

void Drawer::mousePressEvent(QMouseEvent* event) {
    Config::instance->onMousePress(event);
}
