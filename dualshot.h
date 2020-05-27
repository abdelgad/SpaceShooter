#ifndef DUALSHOT_H
#define DUALSHOT_H

#include "animateditem.h"
#include "enemy1.h"
#include "enemy2.h"

class DualShot : public AnimatedItem
{
    Q_OBJECT
    int speed;
public:
    DualShot(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int speed, int x, int y);
private slots:
    void move();
};

#endif // DUALSHOT_H
