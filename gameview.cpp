#include "gameview.h"


GameView::GameView()
{
    this->gameViewWidth = 640;
    this->gameViewHeight = 594;
    this->nbEnemies = 0;
    this->nbEnemiesPerWave = 7;
    this->nbEnemiesKilled = 0;
    this->gameEnded = false;

    //ViewSettings
    setFixedSize(this->gameViewWidth, this->gameViewHeight);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    //SceneSettings
    QGraphicsScene* gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0, 0, this->gameViewWidth, this->gameViewHeight);
    QGraphicsPixmapItem* background = new QGraphicsPixmapItem();
    background->setPixmap(QPixmap((QString(":/images/sprites/Background.png"))));
    gameScene->addItem(background);
    setScene(gameScene);


    //SpaceShip
    QString spaceShipSpriteSheetLocation =  QString(":/images/sprites/PlayerShip.png");
    int spaceShipNumSprites = 4; //Par animation d'une certaine position
    int spaceShipSpriteWidth = 36;
    int spaceShipSpriteHeight = 54;
    int spaceShipSpeed = 15;
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


    //Spawning
    int delayBetweenWaves = 4000; // 4 secondes entre les vagues
    int numWaves = 5;
    for (int i = 0; i < numWaves; i++) // 5 vagues d'ennemies
    {
        this->nbEnemies += this->nbEnemiesPerWave;
        QTimer::singleShot((i * delayBetweenWaves), this, SLOT(spawnWaveOfEnemies()));
    }
}



void GameView::spawnWaveOfEnemies()
{
    //Enemy1
    QString enemy1SpriteSheetLocation = QString(":/images/sprites/EnemyShip1.png");
    int enemy1NumSprites = 3;
    int enemy1SpriteWidth = 19;
    int enemy1SpriteHeight = 24;
    int enemy1Speed = 10;
    int enemy1NumLifePoints = 1;

    //Enemy2
    QString enemy2SpriteSheetLocation = QString(":/images/sprites/EnemyShip2.png");
    int enemy2NumSprites = 3;
    int enemy2SpriteWidth = 23;
    int enemy2SpriteHeight = 26;
    int enemy2Speed = 5;
    int enemy2NumLifePoints = 3;
    int enemy2DistanceBeforeRedirection = 20;

    int xMin = 0;
    int xMax = this->scene()->width() - enemy1SpriteWidth;
    int posX;

    for (int i = 0; i < 6; i++) // 6 enemies1 per wave
    {
        Enemy1* enemy1 = new Enemy1(enemy1SpriteSheetLocation,
                                    enemy1NumSprites,
                                    enemy1SpriteWidth,
                                    enemy1SpriteHeight,
                                    enemy1Speed,
                                    enemy1NumLifePoints
                                    );
        connect(enemy1, SIGNAL(destroyed()), this, SLOT(deathToll()));
        connect(enemy1, SIGNAL(destroyed()), this, SLOT(enemyKilled()));
        posX = (qrand() % ((xMax + 1) - xMin) + xMin);
        enemy1->setPos(posX, 0);
        this->scene()->addItem(enemy1);
    }

    xMin = 0 + enemy2DistanceBeforeRedirection;
    xMax = this->scene()->width() - enemy2SpriteWidth - enemy2DistanceBeforeRedirection;

    for(int i = 0; i < 1; i++) // 1 enemy2 per wave
    {
        Enemy2* enemy2 = new Enemy2(enemy2SpriteSheetLocation,
                                    enemy2NumSprites,
                                    enemy2SpriteWidth,
                                    enemy2SpriteHeight,
                                    enemy2Speed,
                                    enemy2NumLifePoints,
                                    enemy2DistanceBeforeRedirection
                                    );
        connect(enemy2, SIGNAL(destroyed()), this, SLOT(deathToll()));
        connect(enemy2, SIGNAL(destroyed()), this, SLOT(enemyKilled()));
        posX = (qrand() % ((xMax + 1) - xMin) + xMin);
        enemy2->setPos(posX, 0);
        this->scene()->addItem(enemy2);
    }
}


void GameView::enemyKilled()
{
    this->nbEnemiesKilled++;

    if(nbEnemiesKilled % 5 == 0)
    {
        QString bonusBallSpriteSheetLocation = QString(":/images/sprites/BonusBall.png");
        int bonusBallNumSprites = 6;
        int bonusBallSpriteWidth = 34;
        int bonusBallSpriteHeight = 32;
        int duration = 5;

        int xMin = 0;
        int xMax = this->scene()->width() - bonusBallSpriteWidth;
        int yMin = 0;
        int yMax = this->scene()->height() - bonusBallSpriteHeight;

        BonusBall* bonusBall  = new BonusBall(bonusBallSpriteSheetLocation,
                                              bonusBallNumSprites,
                                              bonusBallSpriteWidth,
                                              bonusBallSpriteHeight,
                                              duration
                                           );
        int posX = (qrand() % ((xMax + 1) - xMin) + xMin);
        int posY = (qrand() % ((yMax + 1) - yMin) + yMin);
        bonusBall->setPos(posX, posY);
        this->scene()->addItem(bonusBall);
    }
}

void GameView::deathToll()
{
    nbEnemies--;

    if(nbEnemies == 0 && !gameEnded)
    {
        QGraphicsPixmapItem* youWonMessage = new QGraphicsPixmapItem();
        youWonMessage->setPixmap(QPixmap((QString(":/images/sprites/YouWonMessage.png"))));
        youWonMessage->setPos((this->scene()->width() / 2) - (youWonMessage->boundingRect().width() / 2),
                              (this->scene()->height() / 2) - (youWonMessage->boundingRect().height() / 2));
        this->scene()->addItem(youWonMessage);
        this->gameEnded = true;
    }
}

void GameView::gameOver()
{
    if(!gameEnded)
    {
        QGraphicsPixmapItem* youLostMessage = new QGraphicsPixmapItem();
        youLostMessage->setPixmap(QPixmap((QString(":/images/sprites/YouLost Message.png"))));
        youLostMessage->setPos((this->scene()->width() / 2) - (youLostMessage->boundingRect().width() / 2),
                              (this->scene()->height() / 2) - (youLostMessage->boundingRect().height() / 2));
        this->scene()->addItem(youLostMessage);
        this->gameEnded = true;
    }
}

