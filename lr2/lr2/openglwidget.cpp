#include "openglwidget.h"
#include <cmath>
#include <QtOpenGL>

const QStringList OpenGLWidget::ALPHA_TESTS_NAMES = {
    "GL_NEVER",
    "GL_LESS",
    "GL_EQUAL",
    "GL_LEQUAL",
    "GL_GREATER",
    "GL_NOTEQUAL",
    "GL_GEQUAL",
    "GL_ALWAYS",
};

const GLenum OpenGLWidget::ALPHA_TESTS[] = {
    GL_NEVER,
    GL_LESS,
    GL_EQUAL,
    GL_LEQUAL,
    GL_GREATER,
    GL_NOTEQUAL,
    GL_GEQUAL,
    GL_ALWAYS,
};

const QStringList OpenGLWidget::SFACTORS_NAMES = {
    "GL_ZERO",
    "GL_ONE",
    "GL_DST_COLOR",
    "GL_ONE_MINUS_DST_COLOR",
    "GL_SRC_ALPHA",
    "GL_ONE_MINUS_SRC_ALPHA",
    "GL_DST_ALPHA",
    "GL_ONE_MINUS_DST_ALPHA",
    "GL_SRC_ALPHA_SATURATE",
};

const GLenum OpenGLWidget::SFACTORS[] = {
    GL_ZERO,
    GL_ONE,
    GL_DST_COLOR,
    GL_ONE_MINUS_DST_COLOR,
    GL_SRC_ALPHA,
    GL_ONE_MINUS_SRC_ALPHA,
    GL_DST_ALPHA,
    GL_ONE_MINUS_DST_ALPHA,
    GL_SRC_ALPHA_SATURATE,
};

const QStringList OpenGLWidget::DFACTORS_NAMES = {
    "GL_ZERO",
    "GL_ONE",
    "GL_SRC_COLOR",
    "GL_ONE_MINUS_SRC_COLOR",
    "GL_SRC_ALPHA",
    "GL_ONE_MINUS_SRC_ALPHA",
    "GL_DST_ALPHA",
    "GL_ONE_MINUS_DST_ALPHA",
};

const GLenum OpenGLWidget::DFACTORS[] = {
    GL_ZERO,
    GL_ONE,
    GL_SRC_COLOR,
    GL_ONE_MINUS_SRC_COLOR,
    GL_SRC_ALPHA,
    GL_ONE_MINUS_SRC_ALPHA,
    GL_DST_ALPHA,
    GL_ONE_MINUS_DST_ALPHA,
};

OpenGLWidget::OpenGLWidget(QWidget *parent):
    QOpenGLWidget(parent),
    _alphaTestFunc(ALPHA_TESTS[0]),
    _alphaTestRef(0),
    _scissorX(0),
    _scissorY(0),
    _sfactor(SFACTORS[0]),
    _dfactor(DFACTORS[0])
{}

void OpenGLWidget::initializeGL() {
    glClearColor(1, 1, 1, 1);
    _w = width();
    _h = height();
    setupViewport();
}

void OpenGLWidget::resizeGL(int w, int h) {
    _w = w;
    _h = h;
    setupViewport();
}

void OpenGLWidget::setupViewport() {
    int size = std::min(_w, _h);
    glViewport((_w - size) / 2, (_h - size) / 2, size, size);
}

void OpenGLWidget::paintGL() {
    glEnable(GL_SCISSOR_TEST);
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);
    setupViewport();
    glScissor(
                static_cast<GLint>(static_cast<float>(_w) * _scissorX / 2),
                static_cast<GLint>(static_cast<float>(_h) * _scissorY / 2),
                static_cast<GLsizei>(static_cast<float>(_w) * (1 - _scissorX)),
                static_cast<GLsizei>(static_cast<float>(_h) * (1 - _scissorY)));

    glAlphaFunc(_alphaTestFunc, _alphaTestRef);
    glBlendFunc(_sfactor, _dfactor);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    const double size = 100.0;
    glOrtho(-size, size, size, -size, 1, 0);

    glBegin(GL_POLYGON);
    glColor4d(1, 0, 0, 0.5);
    paintCircleVertices(0, -30, 45);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4d(0, 1, 0, 0.6);
    paintCircleVertices(-30, 15, 45);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4d(0, 0, 1, 0.7);
    paintCircleVertices(30, 15, 45);
    glEnd();


    glDisable(GL_SCISSOR_TEST);
    glDisable(GL_ALPHA_TEST);
    glDisable(GL_BLEND);
}

void OpenGLWidget::paintCircleVertices(double cx, double cy, double radius, int segments)
{
    for(int i = 0; i < segments; i++)
    {
        double theta = 2.0 * 3.1415926 * double(i) / double(segments);
        double x = radius * cos(theta);
        double y = radius * sin(theta);
        glVertex2d(x + cx, y + cy);
    }
}

void OpenGLWidget::setAlphaTestFunc(int func) {
    _alphaTestFunc = ALPHA_TESTS[func];
    update();
}

void OpenGLWidget::setAlphaTestRef(float ref) {
    _alphaTestRef = static_cast<GLclampf>(ref);
    update();
}

void OpenGLWidget::setScissorX(float value) {
    _scissorX = value;
    update();
}

void OpenGLWidget::setScissorY(float value) {
    _scissorY = value;
    update();
}

void OpenGLWidget::setSfactor(int sfactor) {
    _sfactor = SFACTORS[sfactor];
    update();
}

void OpenGLWidget::setDfactor(int dfactor) {
    _dfactor = DFACTORS[dfactor];
    update();
}
