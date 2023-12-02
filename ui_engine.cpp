#include "ui_engine.h"
#include "ui_fieldBoard.h"
#include "ui_button.h"
#include <QGraphicsTextItem>
#include <iostream>

using namespace std;

#include <QDebug>
Game::Game(QWidget *parent){
    // set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);

    // set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);
    setScene(scene);

    // initialize
    cardToPlace = NULL;
}

void Game::start(){
    // clear the screen
    scene->clear();

    // test code TODO remove
    fieldBoard = new FieldBoard();
    fieldBoard->placeFields(200,30,7,7);
    drawGUI();
    createInitialCards();
}

void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    // draws a panel at the specified location with the specified properties
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

void Game::drawGUI(){
    // draw the left panel
    drawPanel(0,0,150,768,Qt::darkCyan,1);

    // draw the right panel
    drawPanel(874,0,150,768,Qt::darkCyan,1);

    // place player 1 text
    QGraphicsTextItem* p1 = new QGraphicsTextItem("Player 1's Cards: ");
    p1->setPos(25,0);
    scene->addItem(p1);

    // place player 1 text
    QGraphicsTextItem* p2 = new QGraphicsTextItem("Player 2's Cards: ");
    p2->setPos(874+25,0);
    scene->addItem(p2);

    // place whosTurnText
    whosTurnText = new QGraphicsTextItem();
    setWhosTurn(QString("PLAYER1"));
    whosTurnText->setPos(490,0);
    scene->addItem(whosTurnText);

}

void Game::createNewCard(QString player){
    // create the card
    Card* card = new Card();
    card->setOwner(player);
    card->setIsPlaced(false);

    // add the card to the proper list
    if (player == QString("PLAYER1")){
        player1Cards.append(card);
    }
    else {
        player2Cards.append(card);
    }

    // draw the cards
    drawCards();
}

void Game::createInitialCards(){
    // create player 1's cards
    for (size_t i = 0, n = 5; i < n; i++){
        createNewCard(QString("PLAYER1"));
    }

    // create player 2's cards
    for (size_t i = 0, n = 5; i < n; i++){
        createNewCard(QString("PLAYER2"));
    }

    drawCards();
}

void Game::drawCards(){
    // traverse through list of cards and draw them

    // remove all of player1's cards from the scene
    for (size_t i = 0, n = player1Cards.size(); i < n; i++){
        scene->removeItem(player1Cards[i]);
    }
    // remove all of player2's cards from the scene
    for (size_t i = 0, n = player2Cards.size(); i < n; i++){
        scene->removeItem(player2Cards[i]);
    }

    // draw player1's cards
    for (size_t i = 0, n = player1Cards.size(); i < n; i++){
        Card* card = player1Cards[i];
        card->setPos(13,25+85*i);
        scene->addItem(card);
    }

    // draw player2's cards
    for (size_t i = 0, n = player2Cards.size(); i < n; i++){
        Card* card = player2Cards[i];
        card->setPos(874+13,25+85*i);
        scene->addItem(card);
    }
}

void Game::displayMainMenu(){
    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Main Menu"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the play button
    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}

QString Game::getWhosTurn(){
    return whosTurn_;
}

void Game::setWhosTurn(QString player){
    // change the QString
    whosTurn_ = player;

    // change the QGraphicsTextItem
    whosTurnText->setPlainText(QString("Whos turn: ") + player);
}

void Game::pickUpCard(Card *card){
    // picks up the specified card
    if (card->getOwner() == getWhosTurn() && cardToPlace == NULL){
        cardToPlace = card;
        originalPos = card->pos();
        return;
}
}

void Game::placeCard(Card *fieldToReplace){
    // replaces the specified field with the cardToPlace
    printf("PlaceCard hivodott");
    cardToPlace->setPos(fieldToReplace->pos());
    fieldBoard->getFields().removeAll(fieldToReplace);
    fieldBoard->getFields().append(cardToPlace);
    scene->removeItem(fieldToReplace);
    cardToPlace->setIsPlaced(true);
    removeFromDeck(cardToPlace,getWhosTurn());
    cardToPlace = NULL;

    // replace the placed card w a new one
    createNewCard(getWhosTurn());

    // make it the next players turn
    nextPlayersTurn();
}

void Game::nextPlayersTurn(){
    if (getWhosTurn() == QString("PLAYER1")){
        setWhosTurn(QString("PLAYER2"));
    }
    else {
        setWhosTurn(QString("PLAYER1"));
    }
}

void Game::removeFromDeck(Card *card, QString player){
    if (player == QString("PLAYER1")){
        // remove from player 1
        player1Cards.removeAll(card);
    }

    if (player == QString("PLAYER2")){
        // remove from player 1
        player2Cards.removeAll(card);
    }

}

void Game::mouseMoveEvent(QMouseEvent *event){
    // if there is a cardToPlace, then make it follow the mouse
    if (cardToPlace){
        QPoint tmp(10,10);
        cardToPlace->setPos(event->pos()+=tmp);
    }

    QGraphicsView::mouseMoveEvent(event);
}

void Game::mousePressEvent(QMouseEvent *event){
    // make right click return cardToPlace to originalPos
    cout << "Jobb klikkk" << endl;
    if (event->button() == Qt::RightButton){
        if (cardToPlace){
            cardToPlace->setPos(originalPos);
            cardToPlace = NULL;
            return;
        }
    }

    QGraphicsView::mousePressEvent(event);
}
