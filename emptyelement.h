#ifndef EMPTYELEMENT_H
#define EMPTYELEMENT_H

#include "direction.h"
#include "fieldelement.h"



class EmptyElement: public FieldElement
{
public:
    EmptyElement(Direction);
    ~EmptyElement();
private:
    std::string whatami() override;
    int moveTrainTo() override;
};

#endif // EMPTYELEMENT_H
