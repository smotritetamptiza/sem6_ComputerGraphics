#include "openglwidget.h"
#include <QtOpenGL>

const QStringList OpenGLWidget::MODES_NAMES = {
    "GL_LINES",
    "GL_LINE_STRIP",
    "GL_LINE_LOOP",
    "GL_TRIANGLES",
    "GL_TRIANGLE_STRIP",
    "GL_TRIANGLE_FAN",
    "GL_POLYGON",
    "GL_QUADS",
    "GL_QUAD_STRIP",
};

const GLenum OpenGLWidget::MODES[] = {
    GL_LINES,
    GL_LINE_STRIP,
    GL_LINE_LOOP,
    GL_TRIANGLES,
    GL_TRIANGLE_STRIP,
    GL_TRIANGLE_FAN,
    GL_POLYGON,
    GL_QUADS,
    GL_QUAD_STRIP,
};

OpenGLWidget::OpenGLWidget(QWidget *parent):
    QOpenGLWidget(parent),
    _mode(0)
{}

void OpenGLWidget::paintGL() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,20,20,0,1,0);
    GL_QUAD_STRIP;

    GLenum mode = MODES[_mode];

    glBegin(mode);
    paintVertices();
    glEnd();
}

void OpenGLWidget::paintVertices() {
    glColor3d(0.766,0.427,0.705);
    glVertex2d(8, 2);

    glColor3d(0.232,0.234,0.655);
    glVertex2d(9, 2);

    glColor3d(0.833,0.594,0.963);
    glVertex2d(16, 4);

    glColor3d(0.109,0.582,0.143);
    glVertex2d(17, 7);

    glColor3d(0.686,0.935,0.789);
    glVertex2d(17, 13);

    glColor3d(0.489,0.1,0.442);
    glVertex2d(16, 16);

    glColor3d(0.156,0.973,0.394);
    glVertex2d(13, 18);

    glColor3d(0.768,0.099,0.964);
    glVertex2d(8, 20);

    glColor3d(0.301,0.085,0.277);
    glVertex2d(4, 16);

    glColor3d(0.184,0.653,0.707);
    glVertex2d(3, 15);

    glColor3d(0.923,0.895,0.048);
    glVertex2d(3, 7);

    glColor3d(0.148,0.274,0.409);
    glVertex2d(4, 4);
}

void OpenGLWidget::onModeChanged(int mode) {
    setMode(mode);
}

void OpenGLWidget::setMode(int mode) {
    _mode = mode;
    update();
}

int OpenGLWidget::mode() {
    return _mode;
}

