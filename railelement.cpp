#include "railelement.h"

RailElement::RailElement(Direction d):FieldElement(d)
{

}

RailElement::~RailElement()
{

}

std::string RailElement::whatami()
{
    return "RailElement";
}

int RailElement::moveTrainTo()
{
    return -1;
}

int RailElement::moveTrainTo(TrainElement&t)
{
    if(containsTrain){
        return -1;
    }
    if(t.d!=this->d){
        if(((t.d==N||t.d==S)&&(this->d==E||this->d==W))||((t.d==E||t.d==W)&&(this->d==N||this->d==S))){
            return -1;
        }
    }
    addTrain();
    return 0;
}
