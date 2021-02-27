#include "pointsiterator.h"

PointsIterator::PointsIterator(const QVector2D& m0, const QVector2D& p0, const QVector2D& p1, const QVector2D& m1, const float& velocity)
{
    a = (p0 - p1) * 1.5f + (m1 - m0) * 0.5f;
    b = -(p0 * 2.5f) + p1 * 2.f - (m1 * 0.5f + m0);
    c = (p1 - m0) * 0.5f;
    d =  p0;
    this->velocity = velocity;
}

QVector2D PointsIterator::of(const float& t) {
    return ((a*t + b) * t + c) * t + d;
}

QVector2D PointsIterator::velocityOf(const float& t) {
    return 3*a*t*t + 2*b*t + c;
}

const QVector2D& PointsIterator::current() {
    if (t <= 0 || t >= 1)
        throw "Iterator is inactive";

    return _current;
}

bool PointsIterator::next() {
    if (t >= 1)
        return false;

    t += velocity / velocityOf(t).length();

    if (t >= 1)
        return false;

    _current = of(t);
    return true;
}
