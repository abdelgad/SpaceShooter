#ifndef BLUEBALL_H
#define BLUEBALL_H


#include <QtMath>
#include "animateditem.h"
#include "spaceship.h"

class BlueBall : public AnimatedItem
{
    Q_OBJECT
    int speed;
    double blueBallAngle;
public:
    BlueBall(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int speed, double blueBallAngle, int x, int y);
private slots:
    /**
     * @brief sert de déplacer le blueball selon le membre "speed" de la classe
     */
    void move();
};

#endif // BLUEBALL_H
