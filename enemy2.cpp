#include "enemy2.h"
#include <QDebug>

Enemy2::Enemy2(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int speed, int numLifePoints)
{
    this->spriteSheet = QPixmap(spriteSheetLocation);
    this->numSprites = numSprites;
    this->spriteWidth = spriteWidth;
    this->spriteHeight = spriteHeight;
    this->numSpritesPerRow = this->spriteSheet.width() / this->spriteWidth;

    this->frameNumber = 1;
    this->speed = speed;
    this->numLifePoints = numLifePoints;
    this->distanceBeforeRedirection = 20;
    this->direction = 1;
    this->distanceTraveled = 0;
    this->immobile = false;

    //Animation
    QTimer *frameTimer = new QTimer();
    connect(frameTimer, SIGNAL(timeout()), this, SLOT(displayNextFrame()));
    frameTimer->start(100);

    //Movement
    QTimer *movementTimer = new QTimer();
    connect(movementTimer, SIGNAL(timeout()), this, SLOT(move()));
    movementTimer->start(100);
}

Enemy2::~Enemy2()
{

}

void Enemy2::displayNextFrame()
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

void Enemy2::move()
{
    if(!immobile)
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

void Enemy2::mobilize()
{
    this->immobile = false;
}
