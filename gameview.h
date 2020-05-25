#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "spaceship.h"
#include "enemy1.h"
#include "numlives.h"
#include "numlifepoints.h"

class GameView : public QGraphicsView
{
    int gameViewWidth;
    int gameViewHeight;

public:
    GameView();
};

#endif // GAMEVIEW_H
