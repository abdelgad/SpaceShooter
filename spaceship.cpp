#include "spaceship.h"
#include <QDebug>

SpaceShip::SpaceShip(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int speed, int numLives, int numLifePoints)
{
    this->spriteSheet =  QPixmap(spriteSheetLocation);
    this->numSprites = numSprites; //Par animation d'une certaine position
    this->spriteWidth = spriteWidth;
    this->spriteHeight = spriteHeight;
    this->numSpritesPerRow = this->spriteSheet.width() / this->spriteWidth;
    this->frameNumber = 1;

    this->speed = speed;
    this->numLives = numLives;
    this->numLifePoints = numLifePoints;

    this->upKeyPressed = false;
    this->downKeyPressed = false;
    this->leftKeyPressed = false;
    this->rightKeyPressed = false;
    this->spaceKeyPressed = false;


    //Animation
    QTimer *frameTimer = new QTimer();
    connect(frameTimer, SIGNAL(timeout()), this, SLOT(displayNextFrame()));
    frameTimer->start(100);

    //Focus
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    //Movement
    QTimer *movementTimer = new QTimer();
    connect(movementTimer, SIGNAL(timeout()), this, SLOT(manageMoveKeys()));
    movementTimer->start(50);
}

void SpaceShip::explode()
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

void SpaceShip::loseNumLifePoints()
{
    this->numLifePoints--;
    emit numLifePointsModified(this->numLifePoints);
    if(numLifePoints == 0)
    {
        this->numLives--;
        emit numLivesModified(this->numLives);
        if(this->numLives == 0)
        {
            this->explode();
            this->scene()->removeItem(this);
            delete this;
        }
        else
        {
            this->numLifePoints = 10;
            emit numLifePointsModified(this->numLifePoints);
        }
    }
}

void SpaceShip::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_Up)
    {
        upKeyPressed = true;
    }
    else if(event->key() == Qt::Key_Down)
    {
        downKeyPressed = true;
    }
    else if(event->key() == Qt::Key_Left)
    {
        this->frameNumber = ((this->numSprites * 1) + 1); //commence l'itération à partir du 5ème frame (le premier 1 correspond à la position 1)
        leftKeyPressed = true;
    }
    else if(event->key() == Qt::Key_Right)
    {
        //TODO: faire un slot pour le changement de position que ça déclenche un changement de framenumber
        this->frameNumber = ((this->numSprites * 2) + 1); ; //commence l'itération à partir du 9ème frame (le 2 correspond à la position 2)
        rightKeyPressed = true;
    }
    else if(event->key() == Qt::Key_Space)
    {

        if(!spaceKeyPressed)
        {
            QString dualShotSpriteSheetLocation = QString(":/images/sprites/DualShot.png");
            int dualShotNumSprites = 3;
            int dualShotSpriteWidth = 32;
            int dualShotSpriteHeight = 32;
            int dualShotSpeed = 10;
            int dualShotX = (this->x() + (this->spriteWidth / 2) - (dualShotSpriteWidth / 2));
            int dualShotY = (this->y()  + (this->spriteHeight / 2) - (dualShotSpriteHeight / 2));


            DualShot* dualShot = new DualShot(dualShotSpriteSheetLocation,
                                              dualShotNumSprites,
                                              dualShotSpriteWidth,
                                              dualShotSpriteHeight,
                                              dualShotSpeed,
                                              dualShotX,
                                              dualShotY);
            this->scene()->addItem(dualShot);
            spaceKeyPressed = true;
        }
    }

}

void SpaceShip::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
        this->upKeyPressed = false;
    }
    else if(event->key() == Qt::Key_Down)
    {
        this->downKeyPressed = false;
    }
    else if(event->key() == Qt::Key_Left)
    {
        this->frameNumber = 1;
        this->leftKeyPressed = false;
    }
    else if(event->key() == Qt::Key_Right)
    {
        this->frameNumber = 1;
        this->rightKeyPressed = false;
    }
    else if(event->key() == Qt::Key_Space)
    {
        this->spaceKeyPressed = false;
    }
}


void SpaceShip::displayNextFrame()
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

void SpaceShip::manageMoveKeys()
{
    if(upKeyPressed && leftKeyPressed && this->x() - speed >= 0  && this->y() - speed >= 0)
        setPos(this->x() - this->speed, this->y() - this->speed);

    else if (upKeyPressed && rightKeyPressed && this->x() + this->spriteWidth + speed <= this->scene()->width()  && this->y() - speed >= 0)
        setPos(this->x() + this->speed, this->y() - this->speed);

    else if (downKeyPressed && leftKeyPressed && this->x() - speed >= 0  && this->y() + this->spriteHeight  + speed <= this->scene()->height())
        setPos(this->x() - this->speed, this->y() + this->speed);

    else if (downKeyPressed && rightKeyPressed && this->x() + this->spriteWidth + speed <= this->scene()->width()  && this->y() + this->spriteHeight + speed <= this->scene()->height())
        setPos(this->x() + this->speed, this->y() + this->speed);

    else if (upKeyPressed && this->y() - speed >= 0)
        setPos(this->x(), this->y() - this->speed);

    else if (downKeyPressed && this->y() + this->spriteHeight + speed <= this->scene()->height())
        setPos(this->x(), this->y() + this->speed);

    else if (rightKeyPressed && this->x() + this->spriteWidth + speed <= this->scene()->width())
        setPos(this->x() + this->speed, this->y());

    else if (leftKeyPressed && this->x() - speed >= 0)
        setPos(this->x() - this->speed, this->y());
}
