#include "blueball.h"


BlueBall::BlueBall(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int speed, double angle, int x, int y)
{
    //SpritesheetInfo
    this->spriteSheet =  QPixmap(spriteSheetLocation);
    this->numSprites = numSprites;
    this->spriteWidth = spriteWidth;
    this->spriteHeight = spriteHeight;
    this->numSpritesPerRow = this->spriteSheet.width() / this->spriteWidth;

    this->frameNumber = 1;
    this->speed = speed;
    this->blueBallAngle = angle;
    this->setPos(x, y);

    //Animation
    QTimer *frameTimer = new QTimer();
    connect(frameTimer, SIGNAL(timeout()), this, SLOT(displayNextFrame()));
    frameTimer->start(150);

    //Movement
    QTimer *movementTimer = new QTimer();
    connect(movementTimer, SIGNAL(timeout()), this, SLOT(move()));
    movementTimer->start(50);
}

void BlueBall::displayNextFrame()
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





