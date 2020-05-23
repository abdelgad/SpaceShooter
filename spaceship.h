#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include <QKeyEvent>
#include "dualshot.h"

class SpaceShip : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    //SpriteSheetInfo
    QPixmap spriteSheet;
    int numSprites; //Par animation d'une certaine position
    int spriteWidth;
    int spriteHeight;
    int numSpritesPerRow;

    int frameNumber;
    int speed;

    bool upKeyPressed;
    bool downKeyPressed;
    bool leftKeyPressed;
    bool rightKeyPressed;
public:
    SpaceShip(QString spriteSheetLocation);
    int getSpaceShipWidth();
    int getSpaceShipHeight();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent* event);
private slots:
    void displayNextFrame();
    void manageMoveKeys();
};

#endif // SPACESHIP_H
