#include "explosion.h"


Explosion::Explosion(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int x, int y)
    :AnimatedItem(spriteSheetLocation, numSprites, spriteWidth, spriteHeight)
{
    this->setPos(x, y);

    //ExplosionEndingTimer
    QTimer *explosionTimer = new QTimer();
    connect(explosionTimer, SIGNAL(timeout()), this, SLOT(explosionEnded()));
    explosionTimer->start((this->numSprites + 1) * 50);
}

void Explosion::explosionEnded()
{
    this->scene()->removeItem(this);
    delete this;
}
