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
