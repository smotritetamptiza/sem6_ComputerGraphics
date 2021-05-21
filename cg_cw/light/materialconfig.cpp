#include "materialconfig.h";


MaterialConfig MaterialConfig::waterFront = {
    GL_FRONT,
    QColor(9, 47, 13, 50),
    QColor(66, 255, 14, 140),
    QColor(48, 161, 0, 100),
    QColor(),
    50,
};
MaterialConfig MaterialConfig::waterBack = {
    GL_BACK,
    QColor(9, 47, 13, 50),
    QColor(66, 255, 14, 50),
    QColor(48, 161, 0, 0),
    QColor(),
    50,
};
MaterialConfig MaterialConfig::iceberg = {
    GL_FRONT,
    QColor(47, 47, 47),
    QColor(198, 221, 255),
    QColor(0, 0, 0),
    //QColor(102, 140, 161),
    QColor(),
    128,
};
MaterialConfig MaterialConfig::icebergBack = {
    GL_BACK,
    QColor(47, 47, 47),
    QColor(198, 221, 255),
    QColor(102, 140, 161),
    QColor(255, 0, 0),
    128,
};


MaterialConfig MaterialConfig::notExactlyWood = {
    GL_FRONT_AND_BACK,
    QColor(54, 33, 14),
    QColor(182, 109, 46),
    QColor(91, 55, 23),
    QColor(),
    10,
};


MaterialConfig MaterialConfig::glassSide = {
    GL_FRONT,
    QColor(0, 26, 15, 128),
    QColor(0, 200, 200, 255),
    QColor(128, 128, 128, 200),
    QColor(),
    50,
};

MaterialConfig MaterialConfig::glassSideBack = {
    GL_BACK,
    QColor(0, 26, 15, 128),
    QColor(0, 200, 200, 128),
    QColor(128, 128, 128, 0),
    QColor(),
    50,
};
