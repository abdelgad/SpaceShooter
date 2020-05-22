#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

class GameView : public QGraphicsView
{
    int gameViewWidth;
    int gameViewHeight;

public:
    GameView();
};

#endif // GAMEVIEW_H
