#include "spaceship.h"
#include <QDebug>

SpaceShip::SpaceShip(QString spriteSheetLocation)
{

//    QString spriteSheetLocation = QString(":/images/sprites/PlayerShip.png");

    this->spriteSheet =  QPixmap(spriteSheetLocation);
    this->numSprites = 4; //Par animation d'une certaine position
    this->spriteHeight = 54;
    this->spriteWidth = 36;
    this->numSpritesPerRow = this->spriteSheet.width() / this->spriteWidth;

    this->frameNumber = 1;
    this->speed = 30;

    this->upKeyPressed = false;
    this->downKeyPressed = false;
    this->leftKeyPressed = false;
    this->rightKeyPressed = false;


    //setPixmap(this->spriteSheet);

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
    movementTimer->start(1000);
}

int SpaceShip::getSpaceShipWidth()
{
    return this->spriteWidth;
}

int SpaceShip::getSpaceShipHeight()
{
    return this->spriteHeight;
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
        //TODO: comme on aura les informations du laser ici on pourra le centrer à l'aide de son width et son height
        //J'envoie le point central de mon spaceship et c'est au dual shot de se positionner par rapport à ça
        DualShot* dualshot = new DualShot((this->x() + (this->spriteWidth / 2)), this->y());
        this->scene()->addItem(dualshot);
    }

}

void SpaceShip::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
        upKeyPressed = false;
    }
    else if(event->key() == Qt::Key_Down)
    {
        downKeyPressed = false;
    }
    else if(event->key() == Qt::Key_Left)
    {
        this->frameNumber = 1;
        leftKeyPressed = false;
    }
    else if(event->key() == Qt::Key_Right)
    {
        this->frameNumber = 1;
        rightKeyPressed = false;
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

    else if (downKeyPressed && this->y() + this->getSpaceShipHeight() + speed <= this->scene()->height())
        setPos(this->x(), this->y() + this->speed);

    else if (rightKeyPressed && this->x() + this->spriteWidth + speed <= this->scene()->width())
        setPos(this->x() + this->speed, this->y());

    else if (leftKeyPressed && this->x() - speed >= 0)
        setPos(this->x() - this->speed, this->y());
}
