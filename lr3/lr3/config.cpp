#include "config.h"
#include "pointsiterator.h"

Config* Config::instance = new Config();

Config::Config() : QObject(nullptr)
{
    points.push_back(QVector2D(50, 100));
    points.push_back(QVector2D(500, 500));
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
