#include "ui_fieldBoard.h"
#include "ui_engine.h"
#include <iostream>

extern Game* game;

using namespace std;

FieldBoard::FieldBoard(){

}

QList<Card *> FieldBoard::getFields(){
    return fields;
}

void FieldBoard::placeFields(int x, int y, int cols, int rows){
    int X_SHIFT = 75;
    int Y_SHIFT = 8;

    for (size_t i = 0, n = cols; i < n; i++){

        createFieldColumn(x+X_SHIFT*i,y+Y_SHIFT,rows,i);
    }
}

void FieldBoard::setTrainInGUI(QPointF pos){

}

void FieldBoard::createFieldColumn(int x, int y, int numOfRows, int cell){
    // creates a column of Hexes at the specified location with the specified
    // number of rows


    QList<QString> names = {"Vátó Kelet", "Sín Észak","130kmh Sín É","Switch","Sín Kelet","Sín Nyugat","Sín Kelet","60 kmh Nyugat","Váltó Dél"
                            ,"30 kmh Dél","Sín Dél", "Váltó Nyugat"};

    QList<FieldElement*> types ={new RailToRightElement(N),new RailElement(N),new HundredAndThirtyLimit(N),new SwitchElement(W),new RailElement(E)
                                 ,new RailElement(W),new RailElement(E),new SixtyLimitElement(W),new RailToRightElement(E)
                                 ,new ThirtyLimitElement(S),new RailElement(S),new RailToRightElement(S)};

    for (size_t i = 0, n = numOfRows; i < n; i++){
        Card* field = new Card();
        field->setPos(x,y+75*i);
        fields.append(field);
        cout << "COUNTER: " <<  nameCounter << endl;
        if (cell == 0 and i < 4){
            //cout << "Elso sor 4 eleme" << endl;
            field->setOwner(QString("left"));
            field->setCardName(names[nameCounter]);
            field->setType(types[nameCounter]);
            field->setIsPlaced(true);
            game->scene->addItem(field);
            nameCounter++;
            if (nameCounter == 3){
                types[nameCounter]->click();
            }
            continue;
        }
        else if(cell == 1 and i == 3){
            //cout << cell << i << nameCounter << names[nameCounter].toStdString() << endl;
            field->setOwner(QString("left"));
            field->setCardName(names[nameCounter]);
            field->setType(types[nameCounter]);
            field->setIsPlaced(true);
            game->scene->addItem(field);
            nameCounter++;
            continue;
        }
        else if(cell == 2 and i == 3){
            field->setOwner(QString("left"));
            field->setCardName(names[nameCounter]);
            field->setType(types[nameCounter]);
            field->setIsPlaced(true);
            game->scene->addItem(field);
            nameCounter++;
            continue;
        }
        else if(cell == 3 and i == 3){
            field->setOwner(QString("left"));
            field->setCardName(names[nameCounter]);
            field->setType(types[nameCounter]);
            field->setIsPlaced(true);
            game->scene->addItem(field);
            nameCounter++;
            continue;
        }
        else if(cell == 3 and i == 2){
            field->setOwner(QString("left"));
            field->setCardName(names[nameCounter]);
            field->setType(types[nameCounter]);
            field->setIsPlaced(true);
            game->scene->addItem(field);
            nameCounter++;
            continue;
        }
        else if(cell == 3 and i == 1){
            field->setOwner(QString("left"));
            field->setCardName(names[nameCounter]);
            field->setType(types[nameCounter]);
            field->setIsPlaced(true);
            game->scene->addItem(field);
            nameCounter++;
            continue;
        }
        else if(cell == 3 and i == 0){
            field->setOwner(QString("left"));
            field->setCardName(names[nameCounter]);
            field->setType(types[nameCounter]);
            field->setIsPlaced(true);
            game->scene->addItem(field);
            nameCounter++;
            continue;
        }
        else if(cell == 2 and i == 0){
            field->setOwner(QString("left"));
            field->setCardName(names[nameCounter]);
            field->setType(types[nameCounter]);
            field->setIsPlaced(true);
            game->scene->addItem(field);
            nameCounter++;
            continue;
        }
        else if(cell == 1 and i == 0){
            field->setOwner(QString("left"));
            field->setCardName(names[nameCounter]);
            field->setType(types[nameCounter]);
            field->setIsPlaced(true);
            game->scene->addItem(field);
            nameCounter++;
            continue;
        }

        game->scene->addItem(field);

        // initialize
        field->setOwner(QString("NOONE"));
        field->setIsPlaced(true);
    }
}
