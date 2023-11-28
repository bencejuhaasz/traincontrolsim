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
