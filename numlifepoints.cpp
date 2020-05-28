#include "numlifepoints.h"


NumLifePoints::NumLifePoints(int currentNumLifePoints, int numLifePointsMax)
{
    this->currentNumLifePoints = currentNumLifePoints;
    this->numLifePointsMax = numLifePointsMax;
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << currentNumLifePoints;
    setPlainText((QString::fromStdString(ss.str())) + QString("/") + QString::number(numLifePointsMax));
    setDefaultTextColor(Qt::white);
    setFont(QFont("arial",20));
}

void NumLifePoints::updateNumLifePoints(int numLifePoints)
{
    this->currentNumLifePoints = numLifePoints;
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << currentNumLifePoints;
    setPlainText((QString::fromStdString(ss.str())) + QString("/") + QString::number(numLifePointsMax));
}
