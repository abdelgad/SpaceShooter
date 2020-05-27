#ifndef ENEMY1_H
#define ENEMY1_H

#include "explosion.h"
#include "spaceship.h"
#include "animateditem.h"

class Enemy1 : public AnimatedItem
{
    Q_OBJECT
    int speed;
    int numLifePoints;

    void explode();
public:
    Enemy1(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int speed, int numLifePoints);
    ~Enemy1();
    void loseNumLifePoints();
private slots:
    void move();
signals:
    void destroyed();
};

#endif // ENEMY1_H
