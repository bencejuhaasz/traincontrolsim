//
// Created by user on 01/12/2023.
//
#include "railelement.h"
#ifndef TRAINENGINE_RAILTORIGHTELEMENT_H
#define TRAINENGINE_RAILTORIGHTELEMENT_H


class RailToRightElement: public RailElement{
public:
    explicit RailToRightElement(Direction);
    ~RailToRightElement();
protected:
    int moveTrainTo() override;
    int moveTrainTo(TrainElement&);
    std::string whatami() override;

    friend class Field;
};


#endif //TRAINENGINE_RAILTORIGHTELEMENT_H
