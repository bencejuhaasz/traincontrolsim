#ifndef UI_ENGINE_H
#define UI_ENGINE_H

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
#include <QGraphicsView>
#include <QGraphicsScene>
#include "ui_fieldBoard.h"
#include "ui_button.h"
#include <ui_field.h>
#include <windows.h>
#include <QThread>
#include <QMouseEvent>
#include <QWaitCondition>
#include <QMutex>

class Game: public QGraphicsView{
    Q_OBJECT
    QThread trainThread;
public:
    // constructors
    Game(QWidget* parent=NULL);

    ~Game() {
        trainThread.quit();
        trainThread.wait();
    }

    // public methods
    void displayMainMenu(int inp);
    QString getWhosTurn();
    QString getCardName();
    bool cardSelected();
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
    QPointF trainPos = QPointF(-1,-1);
    QThread setTrainPosThread;
    Field *engine;

public slots:
    void start();

private:
    // private methods
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void drawGUI();
    void createNewCard(QString player, QString name, FieldElement *direction);
    void createInitialCards();
    void drawCards();
    Direction getDirection(QString name);


    // private attributes
    QString whosTurn_;
    QString selectedName;
    FieldElement *selectedType;
    QGraphicsTextItem* whosTurnText;
    QList<Card* > player1Cards;
    QList<Card* > player2Cards;

    Button *playButton;
};


#endif // UI_ENGINE_H
