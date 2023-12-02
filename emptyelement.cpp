#include "emptyelement.h"


EmptyElement::EmptyElement(Direction d):FieldElement(d)
{
}


EmptyElement::~EmptyElement()
{

}

std::string EmptyElement::whatami()
{
    return "EmptyElement";
}

int EmptyElement::moveTrainTo()
{
    return -1;
}
