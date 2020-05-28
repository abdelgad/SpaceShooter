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
    int nbEnemiesPerWave;
    bool gameEnded;

private slots:
    /**
     * @brief convoque un ensemble d'ennemies (les ajoute à la scène)
     */
    void spawnWaveOfEnemies();
    /**
     * @brief décrémente le nombre d'ennemies qui existent, ce nombre arrivé à 0
     * affiche le YouWon sprite
     */
    void deathToll();
    /**
     * @brief affiche le YouLose sprite à l'écran
     */
    void gameOver();

public:
    GameView();
};

#endif // GAMEVIEW_H
