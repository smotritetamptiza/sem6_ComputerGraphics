#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QObject>
#include <QString>

class OpenGLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    static const QStringList MODES_NAMES;
    static const GLenum MODES[];

    OpenGLWidget(QWidget *parent = nullptr);

public slots:
    void onModeChanged(int mode);

    void setMode(int mode);
    int mode();


protected:
    void paintGL() override;

private:
    int _mode;

    void paintVertices();
};

#endif // OPENGLWIDGET_H
