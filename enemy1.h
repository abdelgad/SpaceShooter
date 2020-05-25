#ifndef ENEMY1_H
#define ENEMY1_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include "explosion.h"
#include "spaceship.h"

class Enemy1 : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    QPixmap spriteSheet;
    int numSprites;
    int spriteWidth;
    int spriteHeight;
    int numSpritesPerRow;
    int frameNumber;

    int speed;
    int numLifePoints;

    void explode();
public:
    Enemy1(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int speed, int numLifePoints);
    ~Enemy1();
    void loseNumLifePoints();
private slots:
    void displayNextFrame();
    void move();
};

#endif // ENEMY1_H
