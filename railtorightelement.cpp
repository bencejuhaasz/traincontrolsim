//
// Created by user on 01/12/2023.
//

#include "railtorightelement.h"

RailToRightElement::RailToRightElement(Direction d) : RailElement(d){

}

int RailToRightElement::moveTrainTo() {
    return -1;
}

int RailToRightElement::moveTrainTo(TrainElement &t) {
    if(containsTrain){
        return -1;
    }
    if(this->d==N){
        if(t.d==S||t.d==E){
            return -1;
        }
    }
    if(this->d==S){
        if (t.d==W||t.d==N){
            return -1;
        }
    }
    if(this->d==E){
        if (t.d==S||t.d==W){
            return -1;
        }
    }
    if(this->d==W){
        if(t.d==E||t.d==N){
            return -1;
        }
    }
    if(t.d!=this->d){
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
    } else{
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
    }
    addTrain();
    return 0;
}

std::string RailToRightElement::whatami() {
    return "RailToRightElement";

}

RailToRightElement::~RailToRightElement() = default;
