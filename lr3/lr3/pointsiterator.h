#include <QVector2D>

#pragma once

class PointsIterator
{
public:
    PointsIterator(const QVector2D& m0, const QVector2D& p0, const QVector2D& p1, const QVector2D& m1, const float& velocity = 10.0f);
    PointsIterator(const PointsIterator& copy);

    bool next();
    const QVector2D& current();
    QVector2D of(const float& t);
    QVector2D velocityOf(const float& t);

    PointsIterator& operator=(const PointsIterator& from);

private:
    QVector2D a,b,c,d;
    float velocity = 10;
    QVector2D _current;
    float t = 0;
};

