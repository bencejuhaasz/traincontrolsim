#include "field.h"
#include "railelement.h"
#include "trainelement.h"
#include "railtoleftelement.h"
#include "railtorightelement.h"
#include "lightelement.h"
#include <thirtylimitelement.h>
#include <sixtylimitelement.h>
#include <hundredandthirtylimit.h>
#include <switchelement.h>
#include <iostream>
#include <string>
#include <thread>
#include <windows.h>

Field::Field()
{
    for (int i=0; i<10;i++)
    {
        for (int j=0;j<10;j++){
            arr[i][j]=new EmptyElement(N);
        }
    }
    arr[0][0]=new RailToRightElement(N);
    arr[0][0]->containsTrain=true;
    arr[0][0]=new TrainElement(E);
    arr[0][1]=new RailElement(E);
    arr[0][2]=new RailElement(E);
    arr[0][3]=new RailToRightElement(E);
    arr[1][3]=new ThirtyLimitElement(S);
    arr[2][3]=new RailElement(S);
    arr[3][3]=new RailToRightElement(S);
    arr[3][2]=new SixtyLimitElement(W);
    //LIGHT DEMO
    arr[3][1]=new RailElement(W);
    //auto L = new LightElement(W);
    //L->click();
    //f->place(3,1,L);
    //LIGHT DEMO

    //SWITCH DEMO
    //f->place(3,0,new RailToRightElement(W));
    auto S = new SwitchElement(W);
    S->click();
    arr[3][0]=S;
    //SWITCH DEMO
    arr[2][0]=new HundredAndThirtyLimit(N);
    arr[1][0]=new RailElement(N);
}


Field::~Field()
{

}

int Field::start(){
    stopped=false;
    this->GameLogic();
    return 0;
}

int Field::stop(){
    stopped=true;
    return 0;
}

int Field::place(int x, int y, FieldElement * element){
    arr[x][y]=element;
    return 0;
}

void Field::GameLogic(){
    while (!stopped) {
        for (int i=0;i<10;i++){
            for (int j=0;j<10;j++){
                if(arr[i][j]->containsTrain==1){
                    if(arr[i][j]->whatami()=="LightElement"){
                        auto L = dynamic_cast<LightElement*>(arr[i][j]);
                        if(L->state==RED){
                            i=0;
                            break;
                        }
                    }
                    if(arr[i][j]->whatami()=="ThirtyLimitElement"){
                        train->speed=3000;
                    }
                    if(arr[i][j]->whatami()=="SixtyLimitElement"){
                        train->speed=2000;
                    }
                    if(arr[i][j]->whatami()=="HundredAndThirtyLimit"){
                        train->speed=1000;
                    }
                    //DEBUG
                    //std::system("clear");
                    //std::cout<<"X: "<< i << "Y: " << j << std::endl;
                    std::cout << "----------"<< std::endl;
                    for (int a = 0; a < 10; ++a) {
                        for (int b = 0; b < 10; ++b) {
                            if(arr[a][b]->containsTrain==1){
                                std::cout << "X";
                            } else {
                                std::cout << "O";
                            }
                        }
                        std::cout << std::endl;
                    }
                    Sleep(train->speed);
                    //DEBUG
                    bool foundNext=false;
                    //goes straight
                    if(train->d==N){
                        int k=i-1;
                        int l=j;
                        if(arr[k][l]){
                            if(arr[k][l]->whatami()!="EmptyElement"&&arr[k][l]->whatami()!="FieldElement"&&arr[k][l]->whatami()!="RailToLeftElement"&&arr[k][l]->whatami()!="RailToRightElement"){
                                if(reinterpret_cast<RailElement*>(arr[k][l])->moveTrainTo(*train)==0){
                                    arr[i][j]->removeTrain();
                                    foundNext= true;
                                    i=0;
                                    break;
                                }
                            }
                        }
                    }
                    if(train->d==S){
                        int k=i+1;
                        int l=j;
                        if(arr[k][l]){
                            if(arr[k][l]->whatami()!="EmptyElement"&&arr[k][l]->whatami()!="FieldElement"&&arr[k][l]->whatami()!="RailToLeftElement"&&arr[k][l]->whatami()!="RailToRightElement"){
                                if(reinterpret_cast<RailElement*>(arr[k][l])->moveTrainTo(*train)==0){
                                    arr[i][j]->removeTrain();
                                    foundNext= true;
                                    i=0;
                                    break;
                                }
                            }
                        }
                    }
                    if(train->d==E){
                        int k=i;
                        int l=j+1;
                        if(arr[k][l]){
                            if(arr[k][l]->whatami()!="EmptyElement"&&arr[k][l]->whatami()!="FieldElement"&&arr[k][l]->whatami()!="RailToLeftElement"&&arr[k][l]->whatami()!="RailToRightElement"){
                                if(reinterpret_cast<RailElement*>(arr[k][l])->moveTrainTo(*train)==0){
                                    arr[i][j]->removeTrain();
                                    foundNext= true;
                                    i=0;
                                    break;
                                }
                            }
                        }
                    }
                    if(train->d==W){
                        int k=i;
                        int l=j-1;
                        if(arr[k][l]){
                            if(arr[k][l]->whatami()!="EmptyElement"&&arr[k][l]->whatami()!="FieldElement"&&arr[k][l]->whatami()!="RailToLeftElement"&&arr[k][l]->whatami()!="RailToRightElement"){
                                if(reinterpret_cast<RailElement*>(arr[k][l])->moveTrainTo(*train)==0){
                                    arr[i][j]->removeTrain();
                                    foundNext= true;
                                    i=0;
                                    break;
                                }
                            }
                        }
                    }
                    if(!foundNext){
                        //turns
                        if(train->d==N){
                            int k=i-1;
                            int l=j;
                            if(arr[k][l]){
                                if(arr[k][l]->whatami()=="RailToLeftElement"){
                                    if(reinterpret_cast<RailToLeftElement*>(arr[k][l])->moveTrainTo(*train)==0){
                                        arr[i][j]->removeTrain();
                                        foundNext= true;
                                        i=0;
                                        break;
                                    }
                                }
                                if(arr[k][l]->whatami()=="RailToRightElement"){
                                    if(reinterpret_cast<RailToRightElement*>(arr[k][l])->moveTrainTo(*train)==0){
                                        arr[i][j]->removeTrain();
                                        foundNext= true;
                                        i=0;
                                        break;
                                    }
                                }
                            }
                        }
                        if(train->d==S){
                            int k=i+1;
                            int l=j;
                            if(arr[k][l]){
                                if(arr[k][l]->whatami()=="RailToLeftElement"){
                                    if(reinterpret_cast<RailToLeftElement*>(arr[k][l])->moveTrainTo(*train)==0){
                                        arr[i][j]->removeTrain();
                                        foundNext= true;
                                        i=0;
                                        break;
                                    }
                                }
                                if(arr[k][l]->whatami()=="RailToRightElement"){
                                    if(reinterpret_cast<RailToRightElement*>(arr[k][l])->moveTrainTo(*train)==0){
                                        arr[i][j]->removeTrain();
                                        foundNext= true;
                                        i=0;
                                        break;
                                    }
                                }
                            }
                        }
                        if(train->d==E){
                            int k=i;
                            int l=j+1;
                            if(arr[k][l]){
                                if(arr[k][l]->whatami()=="RailToLeftElement"){
                                    if(reinterpret_cast<RailToLeftElement*>(arr[k][l])->moveTrainTo(*train)==0){
                                        arr[i][j]->removeTrain();
                                        foundNext= true;
                                        i=0;
                                        break;
                                    }
                                }
                                if(arr[k][l]->whatami()=="RailToRightElement"){
                                    if(reinterpret_cast<RailToRightElement*>(arr[k][l])->moveTrainTo(*train)==0){
                                        arr[i][j]->removeTrain();
                                        foundNext= true;
                                        i=0;
                                        break;
                                    }
                                }

                            }
                        }
                        if(train->d==W){
                            int k=i;
                            int l=j-1;
                            if(arr[k][l]){
                                if(arr[k][l]->whatami()=="RailToLeftElement"){
                                    if(reinterpret_cast<RailToLeftElement*>(arr[k][l])->moveTrainTo(*train)==0){
                                        arr[i][j]->removeTrain();
                                        foundNext= true;
                                        i=0;
                                        break;
                                    }
                                }
                                if(arr[k][l]->whatami()=="RailToRightElement"){
                                    if(reinterpret_cast<RailToRightElement*>(arr[k][l])->moveTrainTo(*train)==0){
                                        arr[i][j]->removeTrain();
                                        foundNext= true;
                                        i=0;
                                        break;
                                    }
                                }

                            }
                        }
                    }
                    if(!foundNext){
                        std::cout << "crash" << std::endl;
                        this->stop();
                    }


                }
            }
        }
    }
}

int Field::placeTrain(int x, int y, Direction d) {
    arr[x][y]->containsTrain=true;
    train=new TrainElement(d);
    return 0;
}
