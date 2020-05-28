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
    /**
     * @brief Reçoit les différentes proprietés d'une spritesheet afin de pouvoir itérer dessus
     * @param spriteSheetLocation
     * @param numSprites
     * @param spriteWidth
     * @param spriteHeight
     */
    AnimatedItem(QString spriteSheetLocation, int numSprites, int spriteWidth, int spriteHeight);
private slots:
    /**
     * @brief permet d'itérer sur les différents frames/sprites d'une spritesheet
     * selon le membre "frameNumber de la classe, le compteur frameNumber commence à 1 et pas à 0
     */
    void displayNextFrame();
};

#endif // ANIMATEDITEM_H
