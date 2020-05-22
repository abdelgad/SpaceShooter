#include "gameview.h"
#include "spaceship.h"
#include<QDebug>

GameView::GameView()
{
    //qInfo() << spaceship->boundingRect().height();

    this->gameViewWidth = 640;
    this->gameViewHeight = 594;

    //SceneSettings
    QGraphicsScene* gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0, 0, this->gameViewWidth, this->gameViewHeight);
    gameScene->setBackgroundBrush(Qt::black);


    //SpaceShip
    SpaceShip* spaceship = new SpaceShip(QString(":/images/sprites/PlayerShip.png"));
    spaceship->setPos((gameScene->width() / 2) - (spaceship->getSpaceShipWidth() / 2),
                      (gameScene->height() / 2) - (spaceship->getSpaceShipHeight() / 2));
    gameScene->addItem(spaceship);

    //ViewSettings
    setScene(gameScene);
    setFixedSize(this->gameViewWidth, this->gameViewHeight);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
