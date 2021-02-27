#include "drawer.h"

#include <config.h>

Drawer::Drawer(QWidget *parent) : QOpenGLWidget(parent)
{
    QObject::connect(Config::instance, SIGNAL(changed()), this, SLOT(configChanged()));
    setMouseTracking(true);
}

void Drawer::initializeGL() {
    glViewport(0, 0, width(), height());
}

void Drawer::resizeGL(int w, int h) {
    glViewport(0, 0, width(), height());
}

void Drawer::paintGL() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, width(), height(), 0, 1, 0);

    Config& config = *Config::instance;

    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_PROGRAM_POINT_SIZE);
    glEnable(GL_POINT_SMOOTH);

    glLineWidth(Config::LineSize);
    glBegin(GL_LINE_STRIP);
    glColor3f(1, 0, 0);
    for (int i = 0; i < config.points.length() - 1; i++) {
        auto& p = config.points[i];
        glVertex2f(p.x(), p.y());

        PointsIterator iterator = config.iteratorFor(i);
        while (iterator.next()) {
            auto& current = iterator.current();
            glVertex2f(current.x(), current.y());
        }
    }

    auto& p = config.points[config.points.length() - 1];
    glVertex2f(p.x(), p.y());
    glEnd();

    glPointSize(Config::PointSize);
    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_POINTS);
    for (int i = 0; i < config.points.length(); i++) {
        auto& p = config.points[i];
        glVertex2f(p.x(), p.y());
    }
    glEnd();

    if (config.hoveredPoint.x() != INFINITE) {
        glColor3f(0.89f, 0.05f, 0.8f);
        glBegin(GL_POINTS);
        glVertex2f(config.hoveredPoint.x(), config.hoveredPoint.y());
        glEnd();
    }

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

void Drawer::mouseReleaseEvent(QMouseEvent *event) {
    Config::instance->onMouseRelease(event);
}
