#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QObject>
#include <QString>

class OpenGLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    static const QStringList ALPHA_TESTS_NAMES;
    static const GLenum ALPHA_TESTS[];

    static const QStringList SFACTORS_NAMES;
    static const GLenum SFACTORS[];

    static const QStringList DFACTORS_NAMES;
    static const GLenum DFACTORS[];

    OpenGLWidget(QWidget *parent = nullptr);

public slots:
    void setAlphaTestFunc(int func);
    void setAlphaTestRef(float ref);
    void setScissorX(float value);
    void setScissorY(float value);
    void setSfactor(int sfactor);
    void setDfactor(int dfactor);


protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    int _w;
    int _h;
    GLenum _alphaTestFunc;
    GLclampf _alphaTestRef;
    float _scissorX;
    float _scissorY;
    GLenum _sfactor;
    GLenum _dfactor;

    void setupViewport();
    void paintCircleVertices(double cx, double cy, double radius, int segments = 360);
};

#endif // OPENGLWIDGET_H
