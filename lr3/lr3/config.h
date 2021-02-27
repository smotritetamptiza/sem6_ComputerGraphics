#pragma once

#include <QMouseEvent>
#include <QObject>

class Config : public QObject
{
    Q_OBJECT
public:
    static Config* instance;

    explicit Config();

    QList<QPoint> points;
    QList<QList<QPoint>> drawPoints;
    int drawPointsCount = 50;
    double pointSize = 5.0;

    bool isAdding = false;
    bool isRemoving = false;

    QPoint* hoveredPoint = nullptr;

    void recomputeDrawPoints();

    void onMouseMove(QMouseEvent* event);
    void onMousePress(QMouseEvent* event);

public slots:
    void addButtonClicked();
    void removeButtonClicked();

signals:
    void changed();
};

