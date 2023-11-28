#include "field.h"

Field::Field()
{
    for (int i=0; i<10;i++)
    {
        for (int j=0;j<10;j++){
            arr[i][j]=new FieldElement(S);
        }
    }
}


Field::~Field()
{

}
