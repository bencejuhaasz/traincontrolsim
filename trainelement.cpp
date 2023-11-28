#include "trainelement.h"


TrainElement::TrainElement(Direction d):FieldElement(d)
{

}


TrainElement::~TrainElement()
{

}

std::string TrainElement::whatami()
{
    return "TrainElement";
}
