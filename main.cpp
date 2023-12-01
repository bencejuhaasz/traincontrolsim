#include "field.h"
#include "railelement.h"
#include "trainelement.h"
#include "direction.h"

int main(int argc, char *argv[])
{

    //test zone
    Field * f = new Field();
    f->place(0,0,new TrainElement(E));
    f->place(1,0,new RailElement(E));
    f->place(2,0,new RailElement(E));
    f->place(3,0,new RailElement(E));
    f->place(4,0,new RailElement(E));
    f->place(4,1,new RailElement(S));
    f->start();
}
