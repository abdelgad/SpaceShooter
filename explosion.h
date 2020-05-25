#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

class Explosion : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    //SpritesheetInfo
    QPixmap spriteSheet;
    int numSprites;
    int spriteWidth;
    int spriteHeight;
    int numSpritesPerRow;
    int frameNumber;
public:
    Explosion(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight, int x, int y);
private slots:
    void displayNextFrame();
    void explosionEnded();
};

#endif // EXPLOSION_H
