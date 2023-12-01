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
    if(state==RED){
        return -1;
    }
    addTrain();
    return 0;
}
