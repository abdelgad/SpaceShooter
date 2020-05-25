#include "gameview.h"
#include<QDebug>


GameView::GameView()
{
    //qInfo() << spaceship->boundingRect().height();

    this->gameViewWidth = 640;
    this->gameViewHeight = 594;
    this->nbEnemies = 0;

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
    int spaceShipNumLives = 0;
    int spaceShipNumLifePoints = 5;
    SpaceShip* spaceship = new SpaceShip(spaceShipSpriteSheetLocation,
                                         spaceShipNumSprites,
                                         spaceShipSpriteWidth,
                                         spaceShipSpriteHeight,
                                         spaceShipSpeed,
                                         spaceShipNumLives,
                                         spaceShipNumLifePoints
                                         );
    connect(spaceship, SIGNAL(destroyed()), this, SLOT(gameOver()));
    spaceship->setPos((gameScene->width() / 2) - (spaceShipSpriteWidth / 2),
                      (gameScene->height() / 2) - (spaceShipSpriteHeight / 2));
    gameScene->addItem(spaceship);


    //NumLivesText
    NumLives* numLivesText = new NumLives(spaceShipNumLives, spaceShipNumLives);
    connect(spaceship, SIGNAL(numLivesModified(int)), numLivesText, SLOT(updateNumLives(int)));
    numLivesText->setPos(0, 0);
    gameScene->addItem(numLivesText);


    //NumLifePointsText
    NumLifePoints* numLifePointsText = new NumLifePoints(spaceShipNumLifePoints, spaceShipNumLifePoints);
    connect(spaceship, SIGNAL(numLifePointsModified(int)), numLifePointsText, SLOT(updateNumLifePoints(int)));
    numLifePointsText->setPos (gameScene->width() - numLifePointsText->boundingRect().width(), 0);
    gameScene->addItem(numLifePointsText);


    //Enemy1
    QString enemy1SpriteSheetLocation = QString(":/images/sprites/EnemyShip1.png");
    int enemy1NumSprites = 3;
    int enemy1SpriteWidth = 19;
    int enemy1SpriteHeight = 24;
    int enemy1Speed = 10;
    int enemyNumLivesPoints = 1;
    for (int i = 0; i < 10; i++)
    {
        Enemy1* enemy1 = new Enemy1(enemy1SpriteSheetLocation,
                                    enemy1NumSprites,
                                    enemy1SpriteWidth,
                                    enemy1SpriteHeight,
                                    enemy1Speed,
                                    enemyNumLivesPoints
                                    );
        connect(enemy1, SIGNAL(destroyed()), this, SLOT(deathToll()));
        enemy1->setPos(gameScene->width() / 3, gameScene->height() / 3);
        gameScene->addItem(enemy1);
        nbEnemies++;
    }
}

void GameView::deathToll()
{
    nbEnemies--;

    if(nbEnemies == 0)
    {
        QGraphicsPixmapItem* youWonMessage = new QGraphicsPixmapItem();
        youWonMessage->setPixmap(QPixmap((QString(":/images/sprites/YouWonMessage.png"))));
        youWonMessage->setPos((this->scene()->width() / 2) - (youWonMessage->boundingRect().width() / 2),
                              (this->scene()->height() / 2) - (youWonMessage->boundingRect().height() / 2));
        this->scene()->addItem(youWonMessage);
    }
}

void GameView::gameOver()
{
    QGraphicsPixmapItem* youLostMessage = new QGraphicsPixmapItem();
    youLostMessage->setPixmap(QPixmap((QString(":/images/sprites/YouLost Message.png"))));
    youLostMessage->setPos((this->scene()->width() / 2) - (youLostMessage->boundingRect().width() / 2),
                          (this->scene()->height() / 2) - (youLostMessage->boundingRect().height() / 2));
    this->scene()->addItem(youLostMessage);
}

