#include "bonusball.h"

BonusBall::BonusBall(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int duration)
    :AnimatedItem(spriteSheetLocation, numSprites, spriteWidth, spriteHeight)
{
    //Disappear after duration
    QTimer::singleShot(duration * 1000, this, SLOT(disappear()));
}

void BonusBall::disappear()
{
    this->scene()->removeItem(this);
    delete this;
}
