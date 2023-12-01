#include "switchelement.h"


SwitchElement::SwitchElement(Direction d):FieldElement(d)
{

}

SwitchElement::~SwitchElement()
{

}

std::string SwitchElement::whatami()
{
    return "SwitchElement";
}

int SwitchElement::click()
{
    if(state==straight){
        state=side;
    } else{
        state=straight;
    }
    return 0;
}

int SwitchElement::moveTrainTo(){
    return -1;
}

int SwitchElement::moveTrainTo(TrainElement& t){
    if(this->d!=t.d){
        if(this->state!=side){
            return -1;
        } else{
            if((this->d==N&&t.d==E)||(this->d==S&&t.d==W)||(this->d==E&&t.d==S)||(this->d==W&&t.d==N)){
                return -1;
            }
        }
    }
    return 0;
}
