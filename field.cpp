#include "field.h"
#include "railelement.h"
#include "trainelement.h"
#include "railtoleftelement.h"
#include "railtorightelement.h"
#include <iostream>
#include <string>
#include <thread>

Field::Field()
{
    for (int i=0; i<10;i++)
    {
        for (int j=0;j<10;j++){
            arr[i][j]=new EmptyElement(N);
        }
    }
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
                    //DEBUG
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
                    sleep(1);
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
