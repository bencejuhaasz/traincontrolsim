//
// Created by user on 01/12/2023.
//

#include "railtoleftelement.h"

RailToLeftElement::RailToLeftElement(Direction d) : RailElement(d){

}

RailToLeftElement::~RailToLeftElement() = default;

int RailToLeftElement::moveTrainTo() {
    return -1;
}

int RailToLeftElement::moveTrainTo(TrainElement &t) {
    if(containsTrain){
        return -1;
    }
    if(this->d==N){
        if(t.d==S||t.d==W){
            return -1;
        }
    }
    if(this->d==S){
        if (t.d==E||t.d==N){
            return -1;
        }
    }
    if(this->d==E){
        if (t.d==N||t.d==W){
            return -1;
        }
    }
    if(this->d==W){
        if(t.d==E||t.d==S){
            return -1;
        }
    }
    if(t.d!=this->d){
        if (this->d==N){
            t.d=E;
        }
        if (this->d==S){
            t.d=W;
        }
        if (this->d==E){
            t.d=S;
        }
        if (this->d==W){
            t.d=N;
        }
    } else{
        if (this->d==N){
            t.d=W;
        }
        if (this->d==S){
            t.d=E;
        }
        if (this->d==E){
            t.d=N;
        }
        if (this->d==W){
            t.d=S;
        }
    }
    addTrain();
    return 0;
}

std::string RailToLeftElement::whatami() {
    return "RailToLeftElement";
}
