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
    int numLives;
    int numLifePoints;

    bool upKeyPressed;
    bool downKeyPressed;
    bool leftKeyPressed;
    bool rightKeyPressed;
    bool spaceKeyPressed;
    void explode();
public:
    SpaceShip(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int speed, int numLives, int numLifePoints);
    ~SpaceShip();
    void loseNumLifePoints();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent* event);
signals:
    void numLivesModified(int);
    void numLifePointsModified(int);
    void destroyed();
private slots:
    void displayNextFrame();
    void manageMoveKeys();
};

#endif // SPACESHIP_H
