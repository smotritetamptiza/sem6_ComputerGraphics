#include "config.h"

Config* Config::instance = new Config();

Config::Config() : QObject(nullptr)
{
    points.append(QPoint(50, 100));
    points.append(QPoint(500, 500));
    recomputeDrawPoints();
}

void Config::recomputeDrawPoints() {
    for (int i = drawPoints.length(); i < points.length() - 1; i++) {
        drawPoints.append(QList<QPoint>());
    }

    for (int point = 0; point < points.length() - 1; point++) {
        for (int i = drawPoints[point].length(); i < drawPointsCount; i++)
            drawPoints[point].append(QPoint());
    }

    // TODO fill drawPoints
}

void Config::onMouseMove(QMouseEvent* event) {
    // TODO
}

void Config::onMousePress(QMouseEvent* event) {
    // TODO
}

void Config::addButtonClicked() {
    // TODO
}

void Config::removeButtonClicked() {
    // TODO
}
