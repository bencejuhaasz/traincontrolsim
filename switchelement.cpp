#include "switchelement.h"
#include <iostream>

using namespace std;


SwitchElement::SwitchElement(Direction d):FieldElement(d)
{
    state=straight;
}

SwitchElement::~SwitchElement()
{

}

std::string SwitchElement::whatami()
{
    if(state==side){
        return "RailToRightElement";
    }
    return "RailElement";
}

int SwitchElement::click()
{
    cout << "click hivodott\n" << endl;
    if(state==straight){
        state=side;
    } else{
        state=straight;
    }
    return 0;
}
