#include "field.h"
#include "railelement.h"
#include "trainelement.h"
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
    if(element->whatami()=="TrainElement"){
        train= dynamic_cast<TrainElement *>(element);
    }
    arr[x][y]=element;
    return 0;
}

void Field::GameLogic(){
    while (!stopped) {
        for (int i=0;i<10;i++){
            for (int j=0;j<10;j++){
                if(arr[i][j]->containsTrain==1){
                    std::cout<<"X: "<< i << "Y: " << j << std::endl;
                    bool foundNext=false;
                    //goes straight
                    if(train->d==N){
                        int k=i;
                        int l=j+1;
                        if(arr[k][l]){
                            if(arr[k][l]->whatami()!="EmptyElement"&&arr[k][l]->whatami()!="FieldElement"){
                                if((arr[k][l]->d==train->d)||(arr[k][l]->d==S&&train->d==N)||(arr[k][l]->d==E&&train->d==W)||(arr[k][l]->d==N&&train->d==S)||(arr[k][l]->d==W&&train->d==E)){
                                    if(reinterpret_cast<RailElement*>(arr[k][l])->moveTrainTo(*train)==0){
                                        arr[i][j]->removeTrain();
                                        foundNext= true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    if(train->d==S){
                        int k=i;
                        int l=j-1;
                        if(arr[k][l]){
                            if(arr[k][l]->whatami()!="EmptyElement"&&arr[k][l]->whatami()!="FieldElement"){
                                if((arr[k][l]->d==train->d)||(arr[k][l]->d==S&&train->d==N)||(arr[k][l]->d==E&&train->d==W)||(arr[k][l]->d==N&&train->d==S)||(arr[k][l]->d==W&&train->d==E)){
                                    if(reinterpret_cast<RailElement*>(arr[k][l])->moveTrainTo(*train)==0){
                                        arr[i][j]->removeTrain();
                                        foundNext= true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    if(train->d==E){
                        int k=i+1;
                        int l=j;
                        if(arr[k][l]){
                            if(arr[k][l]->whatami()!="EmptyElement"&&arr[k][l]->whatami()!="FieldElement"){
                                if((arr[k][l]->d==train->d)||(arr[k][l]->d==S&&train->d==N)||(arr[k][l]->d==E&&train->d==W)||(arr[k][l]->d==N&&train->d==S)||(arr[k][l]->d==W&&train->d==E)){
                                    if(reinterpret_cast<RailElement*>(arr[k][l])->moveTrainTo(*train)==0){
                                        arr[i][j]->removeTrain();
                                        foundNext= true;
                                        i=0;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    if(train->d==W){
                        int k=i-1;
                        int l=j;
                        if(arr[k][l]){
                            if(arr[k][l]->whatami()!="EmptyElement"&&arr[k][l]->whatami()!="FieldElement"){
                                if((arr[k][l]->d==train->d)||(arr[k][l]->d==S&&train->d==N)||(arr[k][l]->d==E&&train->d==W)||(arr[k][l]->d==N&&train->d==S)||(arr[k][l]->d==W&&train->d==E)){
                                    if(reinterpret_cast<RailElement*>(arr[k][l])->moveTrainTo(*train)==0){
                                        arr[i][j]->removeTrain();
                                        foundNext= true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    if(!foundNext){
                        //turns
                        if(arr[i][j]->d==N||arr[i][j]->d==S){
                            for (int k=i-1;k<=i+1;k++){
                                if(arr[k][j]){
                                    if(k!=i){
                                        if(arr[k][j]->whatami()!="EmptyElement"&&arr[k][j]->whatami()!="FieldElement"){
                                            if(reinterpret_cast<RailElement*>(arr[k][j])->moveTrainTo(*train)==0){
                                                //move
                                                arr[i][j]->removeTrain();
                                                train->d=arr[i][j]->d;
                                                foundNext=true;
                                                break;
                                            }
                                        }
                                    }

                                }

                            }
                        }
                        if(arr[i][j]->d==E||arr[i][j]->d==W){
                            for (int l=j-1;l<=j+1;l++){
                                if(arr[i][l]){
                                    if(l!=j){
                                        if(arr[i][l]->whatami()!="EmptyElement"&&arr[i][l]->whatami()!="FieldElement"){
                                            if(reinterpret_cast<RailElement*>(arr[i][l])->moveTrainTo(*train)==0){
                                                //move
                                                arr[i][j]->removeTrain();
                                                train->d=arr[i][j]->d;
                                                foundNext=true;
                                                break;
                                            }
                                        }
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
