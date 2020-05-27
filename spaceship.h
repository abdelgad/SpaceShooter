#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QKeyEvent>
#include "animateditem.h"
#include "dualshot.h"

class SpaceShip : public AnimatedItem
{
    Q_OBJECT
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
    void manageMoveKeys();
};

#endif // SPACESHIP_H
