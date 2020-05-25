#include "numlives.h"


NumLives::NumLives(int currentNumLives, int numLivesMax)
{
    this->currentNumLives = currentNumLives;
    this->numLivesMax = numLivesMax;
    setPlainText(QString("Lives: ") + QString::number(currentNumLives) + QString("/") + QString::number(numLivesMax));
    setDefaultTextColor(Qt::white);
    setFont(QFont("arial",20));
}

void NumLives::updateNumLives(int numLives)
{
    this->currentNumLives = numLives;
    setPlainText(QString("Lives: ") + QString::number(currentNumLives) + QString("/") + QString::number(numLivesMax));
}
