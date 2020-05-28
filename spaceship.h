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

    /**
     * @brief Crée une explosion à la même position actuelle que le spaceship
     */
    void explode();
public:
    SpaceShip(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int speed, int numLives, int numLifePoints);
    ~SpaceShip();
    /**
     * @brief décrémente le nombre de points de vie du spaceship et eventuellement le nombre de vies selon
     * les règles de jeu
     */
    void loseNumLifePoints();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent* event);
signals:
    /**
     * @brief signal émis lorsque le nombre de vies du spaceship est modifié
     */
    void numLivesModified(int);
    /**
     * @brief signal émis lorsque le nombre de points de vie du spaceship est modifié
     */
    void numLifePointsModified(int);
    /**
     * @brief signal émis lorsque le spaceship se fait détruire (delete)
     */
    void destroyed();
private slots:
    void manageMoveKeys();
};

#endif // SPACESHIP_H
