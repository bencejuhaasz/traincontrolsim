#ifndef SWITCHELEMENT_H
#define SWITCHELEMENT_H

#include "trainelement.h"
#include "direction.h"
#include "fieldelement.h"


enum State_{straight, side};

class SwitchElement:public FieldElement
{
public:
    SwitchElement(Direction);
    ~SwitchElement();

    int click() override;

private:
    State_ state;
    std::string whatami() override;
};

#endif // SWITCHELEMENT_H
