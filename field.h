#ifndef FIELD_H
#define FIELD_H
#include "emptyelement.h"
#include "fieldelement.h"
#include "trainelement.h"
#include <thread>


class Field {
public:
    //qt generated
    Field();
    ~Field();
    //game logic access; return -1 is error, 0 is ok
    int place(int x, int y, FieldElement* element); //-1 might mean out of bounds, or game started
    int click(int x, int y); //while running the game, returns -1 if not started and does nothing
    int start(); //should return -1 if called twice ?
    int stop(); //should return -1 if called twice ? should it stop by itself sometimes ? (like crash)
    int clear(); //replaces everything w/ EmptyElement

private:
    TrainElement* train;
    bool stopped=false;
    FieldElement * arr[10][10];
    friend class FieldElement;
    void GameLogic();
};

#endif // FIELD_H
