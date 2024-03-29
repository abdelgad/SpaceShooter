#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "animateditem.h"

class Explosion : public AnimatedItem
{
    Q_OBJECT
public:
    Explosion(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int x, int y);
private slots:
    /**
     * @brief Permet de détruire l'objet explosion (delete) après la fin de l'animation
     */
    void explosionEnded();
};

#endif // EXPLOSION_H
