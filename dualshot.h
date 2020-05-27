#ifndef DUALSHOT_H
#define DUALSHOT_H

//class Enemy1;

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include "enemy1.h"
#include "enemy2.h"

class DualShot : public QObject, public QGraphicsPixmapItem
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
public:
    DualShot(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int speed, int x, int y);
private slots:
    void displayNextFrame();
    void move();
};

#endif // DUALSHOT_H
