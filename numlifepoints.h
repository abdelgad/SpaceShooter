#ifndef NUMLIFEPOINTS_H
#define NUMLIFEPOINTS_H

#include <QObject>
#include <QGraphicsTextItem>
#include <QFont>
#include <sstream>
#include <iomanip>

class NumLifePoints : public QGraphicsTextItem
{
    Q_OBJECT
    int currentNumLifePoints;
    int numLifePointsMax;
public:
    NumLifePoints(int currentNumLifePoints, int numLifePointsMax);
public slots:
    /**
     * @brief met à jour le TextItem selon le numLifePoints reçu en paramètre
     * @param numLifePoints: le nouveau numLifePoints
     */
    void updateNumLifePoints(int numLifePoints);
};

#endif // NUMLIFEPOINTS_H
