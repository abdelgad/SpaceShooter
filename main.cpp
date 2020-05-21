#include "gameview.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameView* gameview = new GameView();
    gameview->show();

    return a.exec();
}
