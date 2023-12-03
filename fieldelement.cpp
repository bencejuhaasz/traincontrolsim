#include "fieldelement.h"
#include <iostream>

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
        std::cout << "added twice" <<std::endl;
        return -1;
    } else{
        addTrain();
        return 0;
    }
}

int FieldElement::removeTrain()
{
    if(!containsTrain){
        std::cout << "removed twice" <<std::endl;
       return -1;
    }
    containsTrain= false;
    return 0;
}

int FieldElement::addTrain() {
    if(containsTrain){
        std::cout << "added twice" <<std::endl;
        return -1;
    }
    containsTrain=true;
    return 0;
}

int FieldElement::click()
{
    return 0;
}

bool FieldElement::getContainsTrain(){
    return containsTrain;
}
