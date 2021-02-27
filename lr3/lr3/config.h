#pragma once

#include "pointsiterator.h"
#include <QMouseEvent>
#include <QObject>
#include <vector>

class Config : public QObject
{
    Q_OBJECT
public:
    static Config* instance;
    static const float PointSize;
    static const float LineSize;

    explicit Config();

    QVector<QVector2D> points;
    QVector2D hoveredPoint = QVector2D(INFINITY, INFINITY);
    QVector2D* movingPoint = nullptr;

    bool isAdding = false;
    bool isRemoving = false;

    QVector2D* findPointUnder(const QVector2D& mouse);
    QVector2D findNearestPoint(PointsIterator& iterator, const QVector2D& mouse);
    void refreshHoveredPoint(QMouseEvent* event);
    void onMouseMove(QMouseEvent* event);
    void onMousePress(QMouseEvent* event);
    void onMouseRelease(QMouseEvent* event);

    PointsIterator iteratorFor(int point);

public slots:
    void addButtonClicked();
    void removeButtonClicked();

signals:
    void changed();
};

