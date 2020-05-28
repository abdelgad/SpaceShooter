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

    /**
     * @brief Crée une explosion à la même position actuelle que l'enemy1
     */
    void explode();
public:
    Enemy1(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int speed, int numLifePoints);
    ~Enemy1();
    /**
     * @brief décrémente le nombre de points de vie de l'enemy1
     */
    void loseNumLifePoints();
private slots:
    /**
     * @brief sert de déplacer l'enemy1 selon le membre "speed" de la classe
     */
    void move();
signals:
    /**
     * @brief signal émis lorsque l'enemy1 se fait détruire (delete)
     */
    void destroyed();
};

#endif // ENEMY1_H
