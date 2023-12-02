#ifndef UI_FIELDBOARD_H
#define UI_FIELDBOARD_H

#include <QList>
#include "ui_field.h"

class FieldBoard{
public:
    // constructors
    FieldBoard();

    // getters/setters
    QList<Card*> getFields();

    // public methods
    void placeFields(int x, int y, int cols, int rows);

private:
    void createFieldColumn(int x, int y, int numOfRows);
    QList<Card*> fields;
};

#endif // UI_FIELDBOARD_H
