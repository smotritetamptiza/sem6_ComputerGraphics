#include "config.h"
#include "pointsiterator.h"
#include <math.h>

Config* Config::instance = new Config();
const float Config::PointSize = 10;
const float Config::LineSize = 3;

Config::Config() : QObject(nullptr)
{
    points.push_back(QVector2D(50, 100));
    points.push_back(QVector2D(500, 500));
    points.push_back(QVector2D(800, 500));
}

void Config::refreshHoveredPoint(QMouseEvent* event) {
    QVector2D mouse(event->localPos());
    QVector2D* nearest = findPointUnder(mouse);

    hoveredPoint.setX(INFINITY);
    hoveredPoint.setY(INFINITY);

    if (nearest) {
        hoveredPoint = *nearest;
        return;
    }

    if (isAdding) {
        QVector2D nearest = QVector2D(INFINITY, INFINITY);

        for (int i = 0; i < points.length() - 1; i++) {
            int k1 = std::max(0, i - 1), k2 = i, k3 = i + 1, k4 = std::min(points.length() - 1, i + 2);
            PointsIterator iterator(points[k1], points[k2], points[k3], points[k4]);
            QVector2D point = findNearestPoint(iterator, mouse);
            if (point.distanceToPoint(mouse) < nearest.distanceToPoint(mouse)) {
                nearest = point;
            }
        }

        if (nearest.distanceToPoint(mouse) < PointSize / 2) {
            hoveredPoint = nearest;
            return;
        }
    }
}

PointsIterator Config::iteratorFor(int i) {
    int k1 = std::max(0, i - 1), k2 = i, k3 = i + 1, k4 = std::min(points.length() - 1, i + 2);
    return PointsIterator(points[k1], points[k2], points[k3], points[k4]);
}

void Config::onMouseMove(QMouseEvent* event) {
    refreshHoveredPoint(event);

    if (movingPoint && !isAdding && !isRemoving) {
        movingPoint->setX(event->x());
        movingPoint->setY(event->y());
    }

    emit changed();
}

void Config::onMousePress(QMouseEvent* event) {
    QVector2D mouse(event->localPos());
    QVector2D* nearest = findPointUnder(mouse);

    if (nearest) {
        movingPoint = nearest;
        emit changed();
        return;
    }
}

void Config::onMouseRelease(QMouseEvent* event) {
    QVector2D mouse(event->localPos());

    if (movingPoint) {
        if (isRemoving) {
            QVector2D* point = findPointUnder(mouse);

            if (point == movingPoint) {
                points.removeOne(*point);
                isRemoving = false;
            }
        }

        movingPoint = nullptr;
        refreshHoveredPoint(event);
        emit changed();
        return;
    }

    if (isAdding) {
        QVector2D nearest;
        int index = -1;

        for (int i = 0; i < points.length() - 1; i++) {
            int k1 = std::max(0, i - 1), k2 = i, k3 = i + 1, k4 = std::min(points.length() - 1, i + 2);
            PointsIterator iterator(points[k1], points[k2], points[k3], points[k4]);
            QVector2D point = findNearestPoint(iterator, mouse);
            if (point.distanceToPoint(mouse) < nearest.distanceToPoint(mouse) || index == -1) {
                nearest = point;
                index = i;
            }
        }

        if (nearest.distanceToPoint(mouse) < PointSize / 2) {
            isAdding = false;
            points.insert(index + 1, nearest);
            refreshHoveredPoint(event);
            emit changed();
            return;
        }
    }


}

QVector2D Config::findNearestPoint(PointsIterator& iterator, const QVector2D& mouse) {
    QVector2D nearest;

    while (iterator.next()) {
        if (iterator.current().distanceToPoint(mouse) <= nearest.distanceToPoint(mouse)) {
            nearest = iterator.current();
        }
    }

    return nearest;
}

QVector2D* Config::findPointUnder(const QVector2D& mouse) {
    QVector2D* nearest = &points[0];

    for (int i = 1; i < points.length(); i++) {
        if (nearest->distanceToPoint(mouse) > points[i].distanceToPoint(mouse))
            nearest = &points[i];
    }

    if (nearest->distanceToPoint(mouse) <= PointSize / 2)
        return nearest;

    return nullptr;
}

void Config::addButtonClicked() {
    if (isAdding)
        isAdding = false;
    else {
        isAdding = true;
        isRemoving = false;
    }
    emit changed();
}

void Config::removeButtonClicked() {
    if (isRemoving)
        isRemoving = false;
    else {
        isRemoving = true;
        isAdding = false;
    }

    if (points.length() <= 2)
        isRemoving = false;

    emit changed();
}
