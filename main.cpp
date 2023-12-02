#include "field.h"
#include "railelement.h"
#include "trainelement.h"
#include "direction.h"
#include "railtoleftelement.h"
#include "railtorightelement.h"
#include "lightelement.h"
#include "thirtylimitelement.h"
#include "sixtylimitelement.h"
#include "hundredandthirtylimit.h"
#include "switchelement.h"

int main(int argc, char *argv[])
{

    //test zone
    auto * f = new Field();
    f->place(0,0,new RailToRightElement(N));
    f->placeTrain(0,0,E);
    f->place(0,1,new RailElement(E));
    f->place(0,2,new RailElement(E));
    f->place(0,3,new RailToRightElement(E));
    f->place(1,3,new ThirtyLimitElement(S));
    f->place(2,3,new RailElement(S));
    f->place(3,3,new RailToRightElement(S));
    f->place(3,2,new SixtyLimitElement(W));
    //LIGHT DEMO
    f->place(3,1,new RailElement(W));
    //auto L = new LightElement(W);
    //L->click();
    //f->place(3,1,L);
    //LIGHT DEMO

    //SWITCH DEMO
    //f->place(3,0,new RailToRightElement(W));
    auto S = new SwitchElement(W);
    S->click();
    f->place(3,0,S);
    //SWITCH DEMO
    f->place(2,0,new HundredAndThirtyLimit(N));
    f->place(1,0,new RailElement(N));
    f->start();
}
