#ifndef ANIMATEDITEM_H
#define ANIMATEDITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

class AnimatedItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
protected:
    QPixmap spriteSheet;
    int numSprites;
    int numSpritesPerRow;
    int spriteWidth;
    int spriteHeight;
    int frameNumber;
public:
    AnimatedItem(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight);
private slots:
    void displayNextFrame();
};

#endif // ANIMATEDITEM_H
