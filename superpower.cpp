#include "superpower.h"


SuperPower::SuperPower(int width, int height, int x, int y)
{
    this->width = width;
    this->height = height;

    setRect(0, 0, width, height);
    this->setPos(x, y);
    setBrush(QBrush(QColor(0,0,128,200)));
}

void SuperPower::move(int x, int y)
{
    this->setPos(x, y);
}
