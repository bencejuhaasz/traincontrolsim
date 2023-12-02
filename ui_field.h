#ifndef UI_FIELD_H
#define UI_FIELD_H

#include <QGraphicsPolygonItem>
#include <QGraphicsSceneMouseEvent>

class Card: public QGraphicsPolygonItem{
public:
    // constructors
    Card(QGraphicsItem* parent=NULL);
    // getters
    int getAttackOf(int side);
    bool getIsPlaced();
    QString getOwner();

    // event
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

    // setters
    void setAttackOf(int side, int attack);
    void setOwner(QString player);
    void setIsPlaced(bool b);

private:
    bool isPlaced;
    QString owner;
    int side0Attack;
    int side1Attack;
    int side2Attack;
    int side3Attack;
    int side4Attack;
    int side5Attack;
};

#endif // UI_FIELD_H
