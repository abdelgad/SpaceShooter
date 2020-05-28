#include "enemy2.h"


Enemy2::Enemy2(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int speed, int numLifePoints, int distanceBeforeRedirection)
    :AnimatedItem(spriteSheetLocation, numSprites, spriteWidth, spriteHeight)
{
    this->speed = speed;
    this->numLifePoints = numLifePoints;
    this->distanceBeforeRedirection = distanceBeforeRedirection;
    this->direction = 1;
    this->distanceTraveled = 0;
    this->immobile = false;

    //Movement
    QTimer *movementTimer = new QTimer();
    connect(movementTimer, SIGNAL(timeout()), this, SLOT(move()));
    movementTimer->start(50);

    //Shooting
    QTimer *shootingTimer = new QTimer();
    connect(shootingTimer, SIGNAL(timeout()), this, SLOT(shoot()));
    shootingTimer->start(1500);
}

Enemy2::~Enemy2()
{
    emit destroyed();
}

void Enemy2::explode()
{
    QString explosion1SpriteSheetLocation = QString(":/images/sprites/Explosion2.png");
    int explosion1NumSprites = 8;
    int explosion1SpriteWidth = 64;
    int explosion1SpriteHeight = 64;
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

void Enemy2::loseNumLifePoints()
{
    this->numLifePoints--;

    if(this->numLifePoints == 0)
    {
        this->explode();
        this->scene()->removeItem(this);
        delete this;
    }
}

void Enemy2::move()
{
    if(!immobile)
    {
        QList<QGraphicsItem*> collidingItems = this->collidingItems();
        bool enemy2Collided = false;
        foreach(QGraphicsItem* collidingItem, collidingItems)
        {
            if(typeid(*collidingItem) == typeid(SpaceShip))
            {
                enemy2Collided = true;
                dynamic_cast<SpaceShip*>(collidingItem)->loseNumLifePoints();
            }
        }

        if(enemy2Collided)
        {
            this->loseNumLifePoints();
        }
        else
        {
            this->setPos(this->x() + (speed * this->direction), this->y() + speed);
            this->distanceTraveled += speed;

            if(this->y() >= this->scene()->height())
            {
                this->setPos(this->x(), 0);
            }
            if(distanceTraveled >= distanceBeforeRedirection)
            {
                immobile = true;
                QTimer::singleShot(500, this, SLOT(mobilize()));
                this->direction *= (-1);
                this->distanceTraveled = -distanceBeforeRedirection;
            }
        }
    }
}

void Enemy2::mobilize()
{
    this->immobile = false;
}

void Enemy2::shoot()
{
    QString blueBallSpriteSheetLocation = QString(":/images/sprites/BlueBall.png");
    int blueBallNumSprites = 2;
    int blueBallSpriteWidth = 32;
    int blueBallSpriteHeight = 32;
    int blueBallSpeed = 10;
    double blueBallAngle = 20.0;
    int blueBallX = (this->x() + (this->spriteWidth / 2) - (blueBallSpriteWidth / 2));
    int blueBallY = (this->y() + this->spriteHeight);

    for(int i = -1; i < 2; i++)
    {
        BlueBall* blueBall = new BlueBall(blueBallSpriteSheetLocation,
                                          blueBallNumSprites,
                                          blueBallSpriteWidth,
                                          blueBallSpriteHeight,
                                          blueBallSpeed,
                                          90 + (i * blueBallAngle), //90 pourra être remplacé par une variable enemy2Angle
                                          blueBallX,
                                          blueBallY);
        this->scene()->addItem(blueBall);
    }
}
