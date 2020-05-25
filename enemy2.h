#ifndef ENEMY2_H
#define ENEMY2_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QThread>

class Enemy2 : public QObject, public QGraphicsPixmapItem
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
    int direction;
    int distanceTraveled;
    int distanceBeforeRedirection;
    bool immobile;
;

    void explode();
public:
    Enemy2(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int speed, int numLifePoints);
    ~Enemy2();
    void loseNumLifePoints();
private slots:
    void displayNextFrame();
    void move();
    void mobilize();
signals:
    void destroyed();
};

#endif // ENEMY2_H
