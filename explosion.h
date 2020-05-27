#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "animateditem.h"

class Explosion : public AnimatedItem
{
    Q_OBJECT
public:
    Explosion(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int x, int y);
private slots:
    void explosionEnded();
};

#endif // EXPLOSION_H
