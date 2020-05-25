#ifndef NUMLIFEPOINTS_H
#define NUMLIFEPOINTS_H

#include <QObject>
#include <QGraphicsTextItem>
#include <QFont>

class NumLifePoints : public QGraphicsTextItem
{
    Q_OBJECT
    int currentNumLifePoints;
    int numLifePointsMax;
public:
    NumLifePoints(int currentNumLifePoints, int numLifePointsMax);
public slots:
    void updateNumLifePoints(int numLifePoints);
};

#endif // NUMLIFEPOINTS_H
