#ifndef UI_FIELD_H
#define UI_FIELD_H

#include <QGraphicsPolygonItem>
#include <QGraphicsSceneMouseEvent>
#include <fieldelement.h>

class Card: public QGraphicsPolygonItem{
public:
    // constructors
    Card(QGraphicsTextItem* parent=NULL);
    // getters
    int getAttackOf(int side);
    bool getIsPlaced();
    QString getOwner();
    QString getCardName();
    FieldElement* getType();
    bool stop = true;

    // event
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

    // setters
    void setAttackOf(int side, int attack);
    void setOwner(QString player);
    void setIsPlaced(bool b);
    void setCardName(QString name);
    void setType(FieldElement *type);

private:
    bool isPlaced;
    QString owner;
    QGraphicsSimpleTextItem *textItem;
    QString cardName;
    FieldElement *fieldType;
    int side0Attack;
    int side1Attack;
    int side2Attack;
    int side3Attack;
    int side4Attack;
    int side5Attack;
};

#endif // UI_FIELD_H
