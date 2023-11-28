#include "fieldelement.h"

FieldElement::FieldElement(Direction d)
{
    this->d=d;
}


FieldElement::~FieldElement()
{

}

std::string FieldElement::whatami()
{
    return "FieldElement";
}

int FieldElement::moveTrainTo()
{
    if(this->containsTrain>0){
        return -1;
    } else{
        containsTrain++;
        return 0;
    }
}

int FieldElement::removeTrain()
{
    containsTrain--;
    return 0;
}
