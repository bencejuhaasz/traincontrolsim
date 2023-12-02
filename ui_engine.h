#ifndef UI_ENGINE_H
#define UI_ENGINE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "ui_fieldBoard.h"
#include <QMouseEvent>

class Game: public QGraphicsView{
    Q_OBJECT
public:
    // constructors
    Game(QWidget* parent=NULL);

    // public methods
    void displayMainMenu();
    QString getWhosTurn();
    void setWhosTurn(QString player);
    void pickUpCard(Card* card);
    void placeCard(Card* fieldToReplace);
    void nextPlayersTurn();
    void removeFromDeck(Card* card,QString player);

    // events
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent* event);

    // public attributes
    QGraphicsScene* scene;
    FieldBoard* fieldBoard;
    Card* cardToPlace;
    QPointF originalPos;

public slots:
    void start();

private:
    // private methods
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void drawGUI();
    void createNewCard(QString player);
    void createInitialCards();
    void drawCards();

    // private attributes
    QString whosTurn_;
    QGraphicsTextItem* whosTurnText;
    QList<Card* > player1Cards;
    QList<Card* > player2Cards;
};


#endif // UI_ENGINE_H
