#include "ui_field.h"
#include <QPointF>
#include <QPolygonF>
#include <QVector>
#include <QBrush>
#include "ui_engine.h"
#include <iostream>

extern Game* game;

using namespace std;

Card::Card(QGraphicsTextItem *parent){
    // draw the polygon

    // points needed to draw hexagon: (1,0), (2,0), (3,1), (2,2), (1,2), (0,1)
    QVector<QPointF> squarePoints;
    squarePoints << QPointF(0,0) << QPointF(1,0) << QPointF(1,1) << QPointF(0,1);

    // scale the points
    int SCALE_BY = 75;
    for (size_t i = 0, n = squarePoints.size(); i < n; ++i){
        squarePoints[i] = squarePoints[i] * SCALE_BY;
    }

    // create a polygon with the scaled points
    QPolygonF hexagon(squarePoints);

    // draw the poly
    setPolygon(hexagon);

    // initialize
    isPlaced = false;
    cardName = "";

}

bool Card::getIsPlaced(){
    return isPlaced;
}

QString Card::getOwner(){
    return owner;
}

QString Card::getCardName(){
    return cardName;
}

FieldElement* Card::getType(){
    return fieldType;
}


void Card::mousePressEvent(QGraphicsSceneMouseEvent *event){
    // if this hex is NOT placed (so it is a card) then pick it up
    cout << cardName.toStdString() << endl;
    if (getIsPlaced() == false){
        cout << getIsPlaced() << endl;
        game->pickUpCard(this);
    }

    // if this hex IS placed, then replace it
    if (getIsPlaced() == true and cardName == "" and game->cardSelected()){
        cout << "Kartya le" << endl;
        game->placeCard(this);
    }
    if (cardName == "START/STOP"){
        if(game->engine->stopped){
            cout << "ELINDULT A JATEK\n" << endl;
            game->engine->stopped = false;
        }
        else{
            cout << "MEGALLT A JATEK\n" << endl;
            game->engine->stopped = true;
        }

        //palyara kattint de nem pakol le elemet
    }
    else{}
}

void Card::setOwner(QString player){
    // set the owner
    owner = player;

    // change the color
    if (player == QString("NOONE")){
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::lightGray);
        setBrush(brush);
    }

    else if (player == QString("left")){
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::gray);
        setBrush(brush);
    }

    else if (player == QString("right")){
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::darkRed);
        setBrush(brush);
    }
    else if (player == QString("train")){
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::darkCyan);
        setBrush(brush);
    }
}

void Card::setCardName(QString name){
    // Szöveg hozzáadása a négyzethez
    textItem = new QGraphicsSimpleTextItem(name, this);
    textItem->setPos(10, 30);
    cardName = name;
    isPlaced = false;
}

void Card::setType(FieldElement *type){
    fieldType = type;
}

void Card::setIsPlaced(bool b){
    isPlaced = b;
    cout << getIsPlaced() << endl;
}
