#include "config.h"
#include "pointsiterator.h"

Config* Config::instance = new Config();
const float Config::PointSize = 5;
const float Config::LineSize = 3;

Config::Config() : QObject(nullptr)
{
    points.push_back(QVector2D(50, 100));
    points.push_back(QVector2D(500, 500));
}

void Config::refreshHoveredPoint() {

}

void Config::onMouseMove(QMouseEvent* event) {
    refreshHoveredPoint();
}

void Config::onMousePress(QMouseEvent* event) {
    // TODO
}

void Config::onMouseRelease(QMouseEvent* event) {
    // TODO
}

void Config::addButtonClicked() {
    if (isAdding)
        isAdding = false;
    else {
        isAdding = true;
        isRemoving = false;
    }
    refreshHoveredPoint();
    emit changed();
}

void Config::removeButtonClicked() {
    if (isRemoving)
        isRemoving = false;
    else {
        isRemoving = true;
        isAdding = false;
    }
    refreshHoveredPoint();
    emit changed();
}
