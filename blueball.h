#ifndef BLUEBALL_H
#define BLUEBALL_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QtMath>
#include "spaceship.h"

class BlueBall : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    //SpritesheetInfo
    QPixmap spriteSheet;
    int numSprites;
    int spriteWidth;
    int spriteHeight;
    int numSpritesPerRow;

    int frameNumber;
    int speed;
    double blueBallAngle;
public:
    BlueBall(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int speed, double blueBallAngle, int x, int y);
private slots:
    void displayNextFrame();
    void move();
};

#endif // BLUEBALL_H
