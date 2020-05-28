#ifndef ENEMY2_H
#define ENEMY2_H

#include "animateditem.h"
#include "blueball.h"

class Enemy2 : public AnimatedItem
{
    Q_OBJECT
    int speed;
    int numLifePoints;
    int direction;
    int distanceTraveled;
    int distanceBeforeRedirection;
    bool immobile;

    void explode();
public:
    Enemy2(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int speed, int numLifePoints, int distanceBeforeRedirection);
    ~Enemy2();
    void loseNumLifePoints();
private slots:
    void move();
    void mobilize();
    void shoot();
signals:
    void destroyed();
};

#endif // ENEMY2_H
