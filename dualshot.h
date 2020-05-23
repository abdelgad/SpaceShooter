#ifndef DUALSHOT_H
#define DUALSHOT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

class DualShot : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    //SpritesheetInfo
    QPixmap spriteSheet;
    int numSprites;
    int spriteWidth;
    int spriteHeight;
    int spritesPerRow;

    int frameNumber;
    int speed;
public:
    DualShot(int, int);
    int getSpriteWidth();
    int getSpriteHeight();
private slots:
    void displayNextFrame();
    void move();
};

#endif // DUALSHOT_H
