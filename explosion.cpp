#include "explosion.h"

Explosion::Explosion(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int x, int y)
{
    this->spriteSheet =  QPixmap(spriteSheetLocation);
    this->numSprites = numSprites;
    this->spriteWidth = spriteWidth;
    this->spriteHeight = spriteHeight;
    this->numSpritesPerRow = this->spriteSheet.width() / this->spriteWidth;

    this->frameNumber = 1;
    this->setPos(x, y);

    //Animation
    QTimer *frameTimer = new QTimer();
    connect(frameTimer, SIGNAL(timeout()), this, SLOT(displayNextFrame()));
    frameTimer->start(100);

    QTimer *explosionTimer = new QTimer();
    connect(explosionTimer, SIGNAL(timeout()), this, SLOT(explosionEnded()));
    explosionTimer->start((this->numSprites + 1) * 100);
}

void Explosion::displayNextFrame()
{
    int column = ((frameNumber - 1) % this->numSpritesPerRow) * this->spriteWidth;
    int row = ((frameNumber - 1) / this->numSpritesPerRow) * this->spriteHeight;

    QRect* myRect = new QRect(column, row, spriteWidth, spriteHeight);
    setPixmap(spriteSheet.copy(*myRect));

    if(frameNumber % this->numSprites == 0)
        frameNumber -= (this->numSprites - 1);
    else
        frameNumber += 1;
}

void Explosion::explosionEnded()
{
    this->scene()->removeItem(this);
    delete this;
}
