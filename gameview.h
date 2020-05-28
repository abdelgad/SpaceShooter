#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "spaceship.h"
#include "enemy1.h"
#include "enemy2.h"
#include "numlives.h"
#include "numlifepoints.h"


class GameView : public QGraphicsView
{
    Q_OBJECT
    int gameViewWidth;
    int gameViewHeight;
    int nbEnemies;
    bool gameEnded;

private slots:
    void spawnWaveOfEnemies();
    void deathToll();
    void gameOver();

public:
    GameView();
};

#endif // GAMEVIEW_H
