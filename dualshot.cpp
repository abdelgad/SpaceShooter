#include "dualshot.h"

DualShot::DualShot(int x, int y)
{
    //SpritesheetInfo
    this->spriteSheet =  QPixmap(QString(":/images/sprites/DualShot.png"));
    this->numSprites = 3;
    this->spriteWidth = 32;
    this->spriteHeight = 32;
    this->spritesPerRow = this->spriteSheet.width() / this->spriteWidth;


    this->frameNumber = 1;
    this->speed = 30;
    this->setPos(x - (this->spriteWidth/2), y - this->spriteHeight);

    //setPixmap(this->spriteSheet);

    //Animation
    QTimer *frameTimer = new QTimer();
    connect(frameTimer, SIGNAL(timeout()), this, SLOT(displayNextFrame()));
    frameTimer->start(100);

    //Movement
    QTimer *movementTimer = new QTimer();
    connect(movementTimer, SIGNAL(timeout()), this, SLOT(move()));
    movementTimer->start(50);
}

int DualShot::getSpriteWidth()
{
    return this->spriteWidth;
}

int DualShot::getSpriteHeight()
{
    return this->spriteHeight;
}

void DualShot::displayNextFrame()
{
    int column = ((frameNumber - 1) % this->spritesPerRow) * this->spriteWidth;
    int row = ((frameNumber - 1) / this->spritesPerRow) * this->spriteHeight;

    QRect* myRect = new QRect(column, row, spriteWidth, spriteHeight);
    setPixmap(spriteSheet.copy(*myRect));

    if(frameNumber == numSprites)
        frameNumber = 1;
    else
        frameNumber += 1;
}

void DualShot::move()
{
//    this->setPos(this->x(), this->y() - speed);
//    if(this->y() + this->spriteHeight <= 0)
//    {
//        this->scene()->removeItem(this);
//        delete this;
//    }
}
