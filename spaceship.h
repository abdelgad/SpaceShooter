#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include <QKeyEvent>
#include <QtMath>

class SpaceShip : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    QPixmap spriteSheet;
    int frameNumber;
    int spaceShipWidth;
    int spaceShipHeight;
    int speed;
    bool upKeyPressed;
    bool downKeyPressed;
    bool leftKeyPressed;
    bool rightKeyPressed;

public:
    SpaceShip(QString spriteSheetLocation);
    int getSpaceShipWidth();
    int getSpaceShipHeight();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent* event);
private slots:
    void displayNextFrame();
    void manageMoveKeys();
};

#endif // SPACESHIP_H
