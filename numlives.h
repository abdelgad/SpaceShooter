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
    /**
     * @brief met à jour le TextItem selon le numLives reçu en paramètre
     * @param numLives: le nouveau numLives
     */
    void updateNumLives(int numLives);
};

#endif // NUMLIVES_H
