#include "numlifepoints.h"


NumLifePoints::NumLifePoints(int currentNumLifePoints, int numLifePointsMax)
{
    this->currentNumLifePoints = currentNumLifePoints;
    this->numLifePointsMax = numLifePointsMax;
    setPlainText(QString::number(currentNumLifePoints) + QString("/") + QString::number(numLifePointsMax));
    setDefaultTextColor(Qt::white);
    setFont(QFont("arial",20));
}

void NumLifePoints::updateNumLifePoints(int numLifePoints)
{
    this->currentNumLifePoints = numLifePoints;
    setPlainText(QString::number(currentNumLifePoints) + QString("/") + QString::number(numLifePointsMax));
}
