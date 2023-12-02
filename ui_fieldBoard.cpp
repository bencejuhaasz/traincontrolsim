#include "ui_fieldBoard.h"
#include "ui_engine.h"

extern Game* game;

FieldBoard::FieldBoard(){

}

QList<Card *> FieldBoard::getFields(){
    return fields;
}

void FieldBoard::placeFields(int x, int y, int cols, int rows){
    int X_SHIFT = 90;
    int Y_SHIFT = 30;

    for (size_t i = 0, n = cols; i < n; i++){

        createFieldColumn(x+X_SHIFT*i,y+Y_SHIFT,rows);
    }
}

void FieldBoard::createFieldColumn(int x, int y, int numOfRows){
    // creates a column of Hexes at the specified location with the specified
    // number of rows
    for (size_t i = 0, n = numOfRows; i < n; i++){
        Card* field = new Card();
        field->setPos(x,y+90*i);
        fields.append(field);
        game->scene->addItem(field);

        // initialize
        field->setOwner(QString("NOONE"));
        field->setIsPlaced(true);
    }
}
