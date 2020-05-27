#include "enemy1.h"


Enemy1::Enemy1(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int speed, int numLifePoints)
{
        this->spriteSheet = QPixmap(spriteSheetLocation);
        this->numSprites = numSprites;
        this->spriteWidth = spriteWidth;
        this->spriteHeight = spriteHeight;
        this->numSpritesPerRow = this->spriteSheet.width() / this->spriteWidth;

        this->frameNumber = 1;
        this->speed = speed;
        this->numLifePoints = numLifePoints;

        //Animation
        QTimer *frameTimer = new QTimer();
        connect(frameTimer, SIGNAL(timeout()), this, SLOT(displayNextFrame()));
        frameTimer->start(150);

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

void Enemy1::displayNextFrame()
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
