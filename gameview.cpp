#include "gameview.h"
#include<QDebug>

GameView::GameView()
{
    //qInfo() << spaceship->boundingRect().height();

    this->gameViewWidth = 640;
    this->gameViewHeight = 594;

    //ViewSettings
    setFixedSize(this->gameViewWidth, this->gameViewHeight);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //SceneSettings
    QGraphicsScene* gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0, 0, this->gameViewWidth, this->gameViewHeight);
    gameScene->setBackgroundBrush(Qt::black);
    setScene(gameScene);


    //SpaceShip
    QString spaceShipSpriteSheetLocation =  QString(":/images/sprites/PlayerShip.png");
    int spaceShipNumSprites = 4; //Par animation d'une certaine position
    int spaceShipSpriteWidth = 36;
    int spaceShipSpriteHeight = 54;
    int spaceShipSpeed = 10;
    int spaceShipNumLives = 3;
    int spaceShipNumLifePoints = 10;
    SpaceShip* spaceship = new SpaceShip(spaceShipSpriteSheetLocation,
                                         spaceShipNumSprites,
                                         spaceShipSpriteWidth,
                                         spaceShipSpriteHeight,
                                         spaceShipSpeed,
                                         spaceShipNumLives,
                                         spaceShipNumLifePoints
                                         );
    spaceship->setPos((gameScene->width() / 2) - (spaceShipSpriteWidth / 2),
                      (gameScene->height() / 2) - (spaceShipSpriteHeight / 2));
    gameScene->addItem(spaceship);


    //NumLivesText
    NumLives* numLivesText = new NumLives(spaceShipNumLives, spaceShipNumLives);
    numLivesText->setPos(0, 0);
    gameScene->addItem(numLivesText);
    connect(spaceship, SIGNAL(numLivesModified(int)), numLivesText, SLOT(updateNumLives(int)));


    //NumLifePointsText
    NumLifePoints* numLifePointsText = new NumLifePoints(spaceShipNumLifePoints, spaceShipNumLifePoints);
    numLifePointsText->setPos (gameScene->width() - numLifePointsText->boundingRect().width(), 0);
    gameScene->addItem(numLifePointsText);
    connect(spaceship, SIGNAL(numLifePointsModified(int)), numLifePointsText, SLOT(updateNumLifePoints(int)));


    //Enemy1
    QString enemy1SpriteSheetLocation = QString(":/images/sprites/EnemyShip1.png");
    int enemy1NumSprites = 3;
    int enemy1SpriteWidth = 19;
    int enemy1SpriteHeight = 24;
    int enemy1Speed = 10;
    int enemyNumLivesPoints = 1;
    Enemy1* enemy1 = new Enemy1(enemy1SpriteSheetLocation,
                                enemy1NumSprites,
                                enemy1SpriteWidth,
                                enemy1SpriteHeight,
                                enemy1Speed,
                                enemyNumLivesPoints
                                );
    enemy1->setPos(gameScene->width() / 3, gameScene->height() / 3);
    gameScene->addItem(enemy1);
}
