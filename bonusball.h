#ifndef BONUSBALL_H
#define BONUSBALL_H

#include "animateditem.h"

class BonusBall : public AnimatedItem
{
    Q_OBJECT
public:
    BonusBall(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int duration);
private slots:
    void disappear();
};

#endif // BONUSBALL_H
