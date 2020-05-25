#ifndef NUMLIVES_H
#define NUMLIVES_H

#include <QObject>
#include <QGraphicsTextItem>
#include <QFont>

class NumLives : public QGraphicsTextItem
{
    Q_OBJECT
    int currentNumLives;
    int numLivesMax;
public:
    NumLives(int currentNumLives, int numLivesMax);
public slots:
    void updateNumLives(int numLives);
};

#endif // NUMLIVES_H
