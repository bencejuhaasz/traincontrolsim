#include "hundredandthirtylimit.h"


HundredAndThirtyLimit::HundredAndThirtyLimit(Direction d):FieldElement(d)
{

}


HundredAndThirtyLimit::~HundredAndThirtyLimit()
{

}

std::string HundredAndThirtyLimit::whatami()
{
    return "dundredAndThirtyLimit";
}

int HundredAndThirtyLimit::moveTrainTo()
{
    return -1;
}

int HundredAndThirtyLimit::moveTrainTo(TrainElement&t){
    t.speed=130;
    return 0;
}
