#include "field.h"
#include "railelement.h"
#include "trainelement.h"
#include "direction.h"
#include "railtoleftelement.h"
#include "railtorightelement.h"

int main(int argc, char *argv[])
{

    //test zone
    Field * f = new Field();
    f->place(0,0,new RailToRightElement(N));
    f->placeTrain(0,0,E);
    f->place(0,1,new RailElement(E));
    f->place(0,2,new RailElement(E));
    f->place(0,3,new RailToRightElement(E));
    f->place(1,3,new RailElement(S));
    f->place(2,3,new RailElement(S));
    f->place(3,3,new RailToRightElement(S));
    f->place(3,2,new RailElement(W));
    f->place(3,1,new RailElement(W));
    f->place(3,0,new RailToRightElement(W));
    f->place(2,0,new RailElement(N));
    f->place(1,0,new RailElement(N));
    f->start();
}
