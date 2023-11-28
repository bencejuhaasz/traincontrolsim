#include "lightelement.h"


LightElement::LightElement(Direction d):FieldElement(d)
{

}

LightElement::~LightElement()
{

}

std::string LightElement::whatami()
{
    return "LightElement";
}
