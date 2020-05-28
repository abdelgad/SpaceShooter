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

    /**
     * @brief Crée une explosion à la même position actuelle que l'enemy2
     */
    void explode();
public:
    Enemy2(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int speed, int numLifePoints, int distanceBeforeRedirection);
    ~Enemy2();
    /**
     * @brief décrémente le nombre de points de vie de l'enemy2 et eventuellement le nombre de vies selon
     * les règles de jeu
     */
    void loseNumLifePoints();
private slots:
    /**
     * @brief sert de déplacer l'objet selon le membre "speed" de la classe
     */
    void move();
    /**
     * @brief autorise l'enemy2 à se déplacer
     */
    void mobilize();
    /**
     * @brief crée un blueball devant l'enemy2
     */
    void shoot();
signals:
    /**
     * @brief signal émis lorsque l'enemy1 se fait détruire (delete)
     */
    void destroyed();
};

#endif // ENEMY2_H
