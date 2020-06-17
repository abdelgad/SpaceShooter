#ifndef SUPERPOWER_H
#define SUPERPOWER_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QBrush>



class SuperPower : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
    int width;
    int height;
public:
    SuperPower(int width, int height, int x, int y);

private slots:
    void move(int x, int y);
};

#endif // SUPERPOWER_H
