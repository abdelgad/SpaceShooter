#include "spaceship.h"
#include <QDebug>

SpaceShip::SpaceShip(QString spriteSheetLocation)
{

//    QString spriteSheetLocation = QString(":/images/sprites/PlayerShip.png");

    this->spriteSheet =  QPixmap(spriteSheetLocation);
    this->frameNumber = 1;
    this->spaceShipHeight = 54;
    this->spaceShipWidth = 36;
    this->speed = 30;
    this->upKeyPressed = false;
    this->downKeyPressed = false;
    this->leftKeyPressed = false;
    this->rightKeyPressed = false;


    setPixmap(this->spriteSheet);

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
    return this->spaceShipWidth;
}

int SpaceShip::getSpaceShipHeight()
{
    return this->spaceShipHeight;
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
        this->frameNumber = 5; //commence l'itération à partir du 5ème frame
        leftKeyPressed = true;
    }
    else if(event->key() == Qt::Key_Right)
    {
        this->frameNumber = 9; //commence l'itération à partir du 9ème frame
        rightKeyPressed = true;
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
    int column = ((frameNumber - 1) % 2) * this->spaceShipWidth;
    int row = ((frameNumber - 1) / 2) * this->spaceShipHeight;

    QRect* myRect = new QRect(column, row, spaceShipWidth, spaceShipHeight);
    setPixmap(spriteSheet.copy(*myRect));

    if(frameNumber % 4 == 0)
        frameNumber -= 3;
    else
        frameNumber += 1;
}

void SpaceShip::manageMoveKeys()
{
    if(upKeyPressed && leftKeyPressed && this->x() - speed >= 0  && this->y() - speed >= 0)
        setPos(this->x() - this->speed, this->y() - this->speed);

    else if (upKeyPressed && rightKeyPressed && this->x() + this->spaceShipWidth + speed <= this->scene()->width()  && this->y() - speed >= 0)
        setPos(this->x() + this->speed, this->y() - this->speed);

    else if (downKeyPressed && leftKeyPressed && this->x() - speed >= 0  && this->y() + this->spaceShipHeight  + speed <= this->scene()->height())
        setPos(this->x() - this->speed, this->y() + this->speed);

    else if (downKeyPressed && rightKeyPressed && this->x() + this->spaceShipWidth + speed <= this->scene()->width()  && this->y() + this->spaceShipHeight + speed <= this->scene()->height())
        setPos(this->x() + this->speed, this->y() + this->speed);

    else if (upKeyPressed && this->y() - speed >= 0)
        setPos(this->x(), this->y() - this->speed);

    else if (downKeyPressed && this->y() + this->getSpaceShipHeight() + speed < this->scene()->height())
        setPos(this->x(), this->y() + this->speed);

    else if (rightKeyPressed && this->x() + this->spaceShipWidth + speed <= this->scene()->width())
        setPos(this->x() + this->speed, this->y());

    else if (leftKeyPressed && this->x() - speed >= 0)
        setPos(this->x() - this->speed, this->y());
}
