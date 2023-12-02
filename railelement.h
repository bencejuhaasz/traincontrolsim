#ifndef RAILELEMENT_H
#define RAILELEMENT_H

#include "trainelement.h"
#include "direction.h"
#include "fieldelement.h"



class RailElement: public FieldElement
{
public:
    explicit RailElement(Direction);
    ~RailElement();
private:
    std::string whatami() override;
    int moveTrainTo() override;
    int moveTrainTo(TrainElement&t);
    friend class Field;
};

#endif // RAILELEMENT_H
