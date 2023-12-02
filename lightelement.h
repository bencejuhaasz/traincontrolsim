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

    int click() override;

private:
    State state;
    std::string whatami() override;

    friend class Field;
};

#endif // LIGHTELEMENT_H
