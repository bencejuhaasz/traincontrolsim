#ifndef SWITCHELEMENT_H
#define SWITCHELEMENT_H

#include "trainelement.h"
#include "direction.h"
#include "fieldelement.h"


enum State{straight, side};

class SwitchElement:public FieldElement
{
public:
    SwitchElement(Direction);
    ~SwitchElement();
private:
    State state;
    std::string whatami() override;
    int click() override;
    int moveTrainTo() override;
    int moveTrainTo(TrainElement&);
};

#endif // SWITCHELEMENT_H
