#include "field.h"
#include "railelement.h"
#include "trainelement.h"
#include "direction.h"
#include "railtoleftelement.h"
#include "railtorightelement.h"
#include "lightelement.h"
#include "thirtylimitelement.h"
#include "sixtylimitelement.h"
#include "hundredandthirtylimit.h"
#include "switchelement.h"

#include <QApplication>
#include <ui_engine.h>
#include <ui_backEndThread.h>

Game * game;

#include <QThread>
#include <QWaitCondition>
#include <QMutex>
#include <ui_engine.h>
#include <iostream>

using namespace std;


// Assuming your existing code is part of the Game class

class TrainUpdater : public QThread {
public:
    TrainUpdater(Game* game) : game(game) {}
    void setMiliSec(int inp){
        waitMiliSec = inp;
    }

protected:
    void run() override {

        while (true) {
            Sleep(waitMiliSec);
            if (game->trainPos.x() != -1){
                setMiliSec(250);
            }
            for (int a = 0; a < 10; ++a) {
                for (int b = 0; b < 10; ++b) {
                    if (game->engine->arr[a][b]->getContainsTrain() == 1 and (game->trainPos.x() != a or game->trainPos.y() != b)) {
                        if (game->trainPos.x() == -1) {game->trainPos = QPointF(a, b);}
                            game->fieldBoard->getFields().at(game->trainPos.x() * 10 + game->trainPos.y() * 10)->setOwner(QString("left"));
                            game->trainPos = QPointF(a, b);
                            game->fieldBoard->getFields().at(a * 10 + b * 10)->setOwner("train");
                    }
                }
            }
        }
    }

private:
    Game* game;
    int waitMiliSec = 7500;
};


class BackEndThread : public QThread {
public:
    BackEndThread(Field* field) : field(field) {}

protected:
    void run() override {

        Sleep(10000);
        field->stopped = false;
        field->start();
        /*while(!field->stopped){
            cout << "INDULJAAAAA" << endl;
            field->start();
        }*/

    }

private:
    Field* field;
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game();
    game->show();
    game->displayMainMenu(250);

    TrainUpdater trainUpdater(game);
    trainUpdater.start();

    BackEndThread beThread(game->engine);
    beThread.start();

    return a.exec();


    /*//test zone
    auto * f = new Field();
    f->place(0,0,new RailToRightElement(N));
    f->placeTrain(0,0,E);
    f->place(0,1,new RailElement(E));
    f->place(0,2,new RailElement(E));
    f->place(0,3,new RailToRightElement(E));
    f->place(1,3,new ThirtyLimitElement(S));
    f->place(2,3,new RailElement(S));
    f->place(3,3,new RailToRightElement(S));
    f->place(3,2,new SixtyLimitElement(W));
    //LIGHT DEMO
    f->place(3,1,new RailElement(W));
    //auto L = new LightElement(W);
    //L->click();
    //f->place(3,1,L);
    //LIGHT DEMO

    //SWITCH DEMO
    //f->place(3,0,new RailToRightElement(W));
    auto S = new SwitchElement(W);
    S->click();
    f->place(3,0,S);
    //SWITCH DEMO
    f->place(2,0,new HundredAndThirtyLimit(N));
    f->place(1,0,new RailElement(N));
    f->start();*/

}
