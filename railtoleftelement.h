//
// Created by user on 01/12/2023.
//
#include "railelement.h"
#include <string>
#include "trainelement.h"
#ifndef TRAINENGINE_RAILTOLEFTELEMENT_H
#define TRAINENGINE_RAILTOLEFTELEMENT_H


class RailToLeftElement: public RailElement{
public:
    explicit RailToLeftElement(Direction);
    ~RailToLeftElement();
protected:
    int moveTrainTo() override;
    int moveTrainTo(TrainElement&);
    std::string whatami() override;

    friend class Field;

};


#endif //TRAINENGINE_RAILTOLEFTELEMENT_H
