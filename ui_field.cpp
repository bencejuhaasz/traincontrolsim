#include "ui_field.h"
#include <QPointF>
#include <QPolygonF>
#include <QVector>
#include <QBrush>
#include "ui_engine.h"
#include <iostream>

extern Game* game;

using namespace std;

#include <QDebug> // TODO remove
Card::Card(QGraphicsItem *parent){
    // draw the polygon

    // points needed to draw hexagon: (1,0), (2,0), (3,1), (2,2), (1,2), (0,1)
    QVector<QPointF> squarePoints;
    squarePoints << QPointF(0,0) << QPointF(1,0) << QPointF(1,1) << QPointF(0,1);

    // scale the points
    int SCALE_BY = 90;
    for (size_t i = 0, n = squarePoints.size(); i < n; ++i){
        squarePoints[i] = squarePoints[i] * SCALE_BY;
    }

    // create a polygon with the scaled points
    QPolygonF hexagon(squarePoints);

    // draw the poly
    setPolygon(hexagon);

    // initialize
    isPlaced = false;
}

bool Card::getIsPlaced(){
    return isPlaced;
}

QString Card::getOwner(){
    return owner;
}

void Card::mousePressEvent(QGraphicsSceneMouseEvent *event){
    // if this hex is NOT placed (so it is a card) then pick it up
    cout << "Na itt a baj" << endl;
    if (getIsPlaced() == false){
        cout << getIsPlaced() << endl;
        game->pickUpCard(this);
    }

    // if this hex IS placed, then replace it
    else {
        cout << "Kartya le" << endl;
        game->placeCard(this);
    }
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

    if (player == QString("PLAYER1")){
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::blue);
        setBrush(brush);
    }

    if (player == QString("PLAYER2")){
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::red);
        setBrush(brush);
    }
}

void Card::setIsPlaced(bool b){
    isPlaced = b;
    cout << getIsPlaced() << endl;
}
