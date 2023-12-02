#include "lightelement.h"


LightElement::LightElement(Direction d):FieldElement(d)
{
    state=GREEN;
}

LightElement::~LightElement()
{

}

std::string LightElement::whatami()
{
    return "LightElement";
}

int LightElement::click()
{
    if(state==GREEN){
        state=RED;
    } else{
        state=GREEN;
    }
    return 0;
}

int LightElement::moveTrainTo(){
    return -1;
}

int LightElement::moveTrainTo(TrainElement &t) {
    if(state==RED){
        t.speed=0;
        return -1;
    }
    addTrain();
    return 0;
}
