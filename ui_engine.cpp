#include "ui_engine.h"
#include <QGraphicsTextItem>
#include <iostream>
#include <QThread>
#include <QDebug>
#include <QWaitCondition>
#include <QMutex>

using namespace std;

Game::Game(QWidget *parent){
    // set up the screen
    setWindowTitle(QString("Train Control Simulation"));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);

    // set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);
    setScene(scene);

    // initialize
    cardToPlace = NULL;
    engine = new Field();

    //TrainThread *trainthr = new TrainThread;
    //trainthr->moveToThread(&trainThread);
    //connect(&trainThread, &QThread::finished, trainthr, &QObject::deleteLater);
    //connect(this, &Game::operate, trainthr, &TrainThread::checkTrain);
    //connect(trainthr, &TrainThread::trainPos, this, &Game::handleTrainPos);
    //.start();
}

void Game::start(){
    // Create the TrainUpdater instance
    // clear the screen
    scene->clear();

    // test code TODO remove
    fieldBoard = new FieldBoard();
    fieldBoard->placeFields(140,0,10,10);
    drawGUI();
    createInitialCards();



    //emit operate(*engine);
    //moveToThread(&setTrainPosThread);
    //connect(playButton, SIGNAL(clicked()), &setTrainPosThread, SLOT(setTrainPos()));
    //setTrainPosThread.start();
    //setTrainPos();
    //std::thread trainPosGUI(this->setTrainPos);

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
    drawPanel(0,0,130,768,Qt::darkGreen,1);

    // draw the right panel
    drawPanel(899,0,125,768,Qt::darkGreen,1);
}

void Game::createNewCard(QString player, QString name, FieldElement *type){
    // create the card
    Card* card = new Card();
    card->setOwner(player);
    card->setCardName(name);
    card->setType(type);
    card->setIsPlaced(false);

    // add the card to the proper list
    if (player == QString("left")){
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
    createNewCard(QString("left"), QString("Sín Észak"), new RailElement(N));
    createNewCard(QString("left"), QString("Sín Dél"), new RailElement(S));
    createNewCard(QString("left"), QString("Sín Kelet"), new RailElement(E));
    createNewCard(QString("left"), QString("Sín Nyugat"), new RailElement(W));
    createNewCard(QString("left"), QString("Lámpa"), new LightElement(N));
    createNewCard(QString("left"), QString("Vonat"), new TrainElement(N));
    //createNewCard(QString("left"), QString("Állomás"), new RailElement(N));
    createNewCard(QString("left"), QString("Csatlakozás"), new SwitchElement(N));

    // create player 2's cards
    createNewCard(QString("right"), QString("START/STOP"), new RailElement(N));
    createNewCard(QString("right"), QString("30 km/h"), new ThirtyLimitElement(N));
    createNewCard(QString("right"), QString("60 km/h"), new SixtyLimitElement(N));
    createNewCard(QString("right"), QString("100 km/h"), new HundredAndThirtyLimit(N));

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
        card->setPos(899+13,25+85*i);
        scene->addItem(card);
    }
}

/*void Game::initialFieldBoardCards(){

        Card* field = new Card();
        field->setPos(x,y+75*i);
        fields.append(field);
        game->scene->addItem(field);

        // initialize
        field->setOwner(QString("NOONE"));
        field->setIsPlaced(true);
    Card* field = new Card();

}*/

void Game::displayMainMenu(int inp){
    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Main Menu"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the play button
    playButton = new Button(QString("Play"));
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

QString Game::getCardName(){
    return selectedName;
}

bool Game::cardSelected(){
    return cardToPlace != NULL;
}

Direction Game::getDirection(QString name){
    if (name == "Sín Észak"){
        return N;
    }
    else if (name == "Sín Dél"){
        return S;
    }
    else if (name == "Sín Kelet"){
        return E;
    }
    else if (name == "Sín Nyugat"){
        return W;
    }
    else{
        return E;
    }
}



/*void Game::handleTrainPos(const QPointF &pos){
   *cout << "MEGHIVODOTT A HANDLETRAINPOS" << endl;
    if((pos.x() != trainPos.x() or pos.y() != trainPos.y())){
        cout << "Talalt ilyen elementet\n" << endl;
        if (trainPos.x() == -1){trainPos = QPointF(pos.x(),pos.y());}
        fieldBoard->getFields().at(trainPos.x()*10+trainPos.y()*10)->setOwner(QString("left"));
        trainPos = QPointF(pos.x(),pos.y());
        fieldBoard->getFields().at(pos.x()*10+pos.y()*10)->setOwner("train");
    }
    while (true){
        Sleep(250);
        for (int a = 0; a < 10; ++a) {
            for (int b = 0; b < 10; ++b) {
                //cout << (engine->arr[a][b]->getContainsTrain()==1) << endl;
                if(engine->arr[a][b]->getContainsTrain()==1 and (pos.x() != trainPos.x() or pos.y() != trainPos.y())){
                    //emit trainPos(QPointF(a,b));
                    cout << "Talalt ilyen elementet\n" << endl;
                    if (trainPos.x() == -1){trainPos = QPointF(a,b);}
                    fieldBoard->getFields().at(trainPos.x()*10+trainPos.y()*10)->setOwner(QString("left"));
                    trainPos = QPointF(a,b);
                    fieldBoard->getFields().at(a*10+b*10)->setOwner("train");
                }
                //cout << "Nem talalt" << endl;
            }
        }
    }


}*/

void Game::pickUpCard(Card *card){
    // picks up the specified card
    if (card->getOwner() == QString("left") && cardToPlace == NULL){
        cardToPlace = card;
        originalPos = card->pos();
        selectedName = card->getCardName();
        selectedType = card->getType();
        return;
    }
    else{
        cout << "Jobbos elemek" << endl;
    }
}

void Game::placeCard(Card *fieldToReplace){
    // replaces the specified field with the cardToPlace
    printf("PlaceCard hivodott");
    cardToPlace->setPos(fieldToReplace->pos());

    fieldBoard->getFields().removeOne(fieldToReplace);

    fieldBoard->getFields().append(cardToPlace);

    scene->removeItem(fieldToReplace);

    cardToPlace->setIsPlaced(true);

    removeFromDeck(cardToPlace,QString("left"));

    cardToPlace = NULL;

    // replace the placed card w a new one
    createNewCard(QString("left"), getCardName(), selectedType);

    //set info in backend engine
    int posx = fieldToReplace->pos().x();
    int posy = fieldToReplace->pos().y();
    engine->place(posx, posy, selectedType);
    for(int a = 0; a < 10; a++)
     {
       for(int b = 0; b < 10; b++)
       {
         cout << engine->arr[a][b];
       }
       cout << endl;
     }
}

void Game::removeFromDeck(Card *card, QString player){
    if (player == QString("left")){
        // remove from player 1
        player1Cards.removeAll(card);
    }

    if (player == QString("right")){
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
