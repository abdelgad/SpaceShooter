#include "enemy1.h"


Enemy1::Enemy1(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int speed, int numLifePoints)
    : AnimatedItem(spriteSheetLocation, numSprites, spriteWidth, spriteHeight)
{
        this->speed = speed;
        this->numLifePoints = numLifePoints;

        //Movement
        QTimer *movementTimer = new QTimer();
        connect(movementTimer, SIGNAL(timeout()), this, SLOT(move()));
        movementTimer->start(50);
}

Enemy1::~Enemy1()
{
    emit destroyed();
}

void Enemy1::explode()
{
    QString explosion1SpriteSheetLocation = QString(":/images/sprites/Explosion1.png");
    int explosion1NumSprites = 8;
    int explosion1SpriteWidth = 32;
    int explosion1SpriteHeight = 32;
    int x = this->x() + (this->spriteWidth / 2) - (explosion1SpriteWidth / 2);
    int y = this->y() + (this->spriteHeight / 2) - (explosion1SpriteHeight / 2);
    Explosion* explosion  = new Explosion(explosion1SpriteSheetLocation,
                                          explosion1NumSprites,
                                          explosion1SpriteWidth,
                                          explosion1SpriteHeight,
                                          x,
                                          y);
    this->scene()->addItem(explosion);
}

void Enemy1::loseNumLifePoints()
{
    this->numLifePoints--;
    if(this->numLifePoints == 0)
    {
        this->explode();
        this->scene()->removeItem(this);
        delete this;
    }
}

void Enemy1::move()
{
    QList<QGraphicsItem*> collidingItems = this->collidingItems();
    bool enemy1Collided = false;
    foreach(QGraphicsItem* collidingItem, collidingItems)
    {
        if(typeid(*collidingItem) == typeid(SpaceShip))
        {
            enemy1Collided = true;
            dynamic_cast<SpaceShip*>(collidingItem)->loseNumLifePoints();
        }
    }

    if(enemy1Collided)
    {
        this->loseNumLifePoints();
    }
    else
    {
        this->setPos(this->x(), this->y() + speed);
        if(this->y() >= this->scene()->height())
        {
            this->setPos(this->x(), 0);
        }
    }
}
