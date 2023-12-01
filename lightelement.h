#ifndef LIGHTELEMENT_H
#define LIGHTELEMENT_H

#include "trainelement.h"
#include "direction.h"
#include "fieldelement.h"


enum State{GREEN,RED};

class LightElement: public FieldElement
{
public:
    LightElement(Direction);
    ~LightElement();
private:
    State state;
    std::string whatami() override;
    int click() override;
    int moveTrainTo() override;
};

#endif // LIGHTELEMENT_H
