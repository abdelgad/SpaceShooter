#include "blueball.h"


BlueBall::BlueBall(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int speed, double angle, int x, int y)
    :AnimatedItem(spriteSheetLocation, numSprites, spriteWidth, spriteHeight)
{
    this->speed = speed;
    this->blueBallAngle = angle;
    this->setPos(x, y);

    //Movement
    QTimer *movementTimer = new QTimer();
    connect(movementTimer, SIGNAL(timeout()), this, SLOT(move()));
    movementTimer->start(50);
}

void BlueBall::move()
{
    QList<QGraphicsItem*> collidingItems = this->collidingItems();
    bool blueBallCollided = false;
    foreach(QGraphicsItem* collidingItem, collidingItems)
    {
        if(typeid(*collidingItem) == typeid(SpaceShip))
        {
            blueBallCollided = true;
            dynamic_cast<SpaceShip*>(collidingItem)->loseNumLifePoints();
        }
    }

    if(blueBallCollided)
    {
        this->scene()->removeItem(this);
        delete this;
    }
    else
    {
        double dx = speed * qCos(qDegreesToRadians(this->blueBallAngle));
        double dy = speed * qSin(qDegreesToRadians(this->blueBallAngle));
        setPos(QPointF(this->x() + dx, this->y() + dy));

        if(this->y() + this->spriteHeight <= 0)
        {
            this->scene()->removeItem(this);
            delete this;
        }
    }
}





