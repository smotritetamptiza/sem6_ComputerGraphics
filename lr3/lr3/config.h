#pragma once

#include <QMouseEvent>
#include <QObject>
#include <vector>

class Config : public QObject
{
    Q_OBJECT
public:
    static Config* instance;

    explicit Config();

    QVector<QVector2D> points;
    double pointSize = 5.0;

    bool isAdding = false;
    bool isRemoving = false;

    void onMouseMove(QMouseEvent* event);
    void onMousePress(QMouseEvent* event);

public slots:
    void addButtonClicked();
    void removeButtonClicked();

signals:
    void changed();
};

