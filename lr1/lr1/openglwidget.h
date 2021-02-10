#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QObject>
#include <QString>

class OpenGLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    static const int MODE_GL_LINES;
    static const int MODE_GL_LINE_STRIP;
    static const int MODE_GL_LINE_LOOP;
    static const int MODE_GL_TRIANGLES;
    static const int MODE_GL_TRIANGLE_STRIP;
    static const int MODE_GL_TRIANGLE_FAN;
    static const int MODE_GL_POLYGON;
    static const int MODE_GL_QUADS;
    static const int MODE_GL_QUAD_STRIP;

    static const QStringList MODES;

    OpenGLWidget(QWidget *parent = nullptr);

public slots:
    void onModeChanged(int mode);

    void setMode(int mode);
    int mode();


protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    int _mode;
    int _w;
    int _h;

    void paintVertices();
};

#endif // OPENGLWIDGET_H
