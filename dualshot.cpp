#include "dualshot.h"

DualShot::DualShot(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int speed, int x, int y)
{
    //SpritesheetInfo
    this->spriteSheet =  QPixmap(spriteSheetLocation);
    this->numSprites = numSprites;
    this->spriteWidth = spriteWidth;
    this->spriteHeight = spriteHeight;
    this->numSpritesPerRow = this->spriteSheet.width() / this->spriteWidth;

    this->frameNumber = 1;
    this->speed = speed;
    this->setPos(x, y);

    //Animation
    QTimer *frameTimer = new QTimer();
    connect(frameTimer, SIGNAL(timeout()), this, SLOT(displayNextFrame()));
    frameTimer->start(100);

    //Movement
    QTimer *movementTimer = new QTimer();
    connect(movementTimer, SIGNAL(timeout()), this, SLOT(move()));
    movementTimer->start(50);
}

void DualShot::displayNextFrame()
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

void DualShot::move()
{
    QList<QGraphicsItem*> collidingItems = this->collidingItems();
    bool dualShotCollided = false;
    foreach(QGraphicsItem* collidingItem, collidingItems)
    {
        if(typeid(*collidingItem) == typeid(Enemy1))
        {
            dualShotCollided = true;
            dynamic_cast<Enemy1*>(collidingItem)->loseNumLifePoints();
            this->scene()->removeItem(this);
            delete this;
        }
    }

    if(!dualShotCollided)
    {
        this->setPos(this->x(), this->y() - speed);
        if(this->y() + this->spriteHeight <= 0)
        {
            this->scene()->removeItem(this);
            delete this;
        }
    }
}
