#include "dualshot.h"


DualShot::DualShot(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int speed, int x, int y)
    :AnimatedItem(spriteSheetLocation, numSprites, spriteWidth, spriteHeight)
{
    this->speed = speed;
    this->setPos(x, y);

    //Movement
    QTimer *movementTimer = new QTimer();
    connect(movementTimer, SIGNAL(timeout()), this, SLOT(move()));
    movementTimer->start(50);
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
        }
        else if(typeid(*collidingItem) == typeid(Enemy2))
        {
            dualShotCollided = true;
            dynamic_cast<Enemy2*>(collidingItem)->loseNumLifePoints();
        }
    }

    if(dualShotCollided)
    {
        this->scene()->removeItem(this);
        delete this;
    }
    else
    {
        this->setPos(this->x(), this->y() - speed);
        if(this->y() + this->spriteHeight <= 0)
        {
            this->scene()->removeItem(this);
            delete this;
        }
    }
}
