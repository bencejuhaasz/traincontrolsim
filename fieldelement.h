#ifndef FIELDELEMENT_H
#define FIELDELEMENT_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>


class FieldElement {
public:
    FieldElement();
    ~FieldElement();
private:
    int click();
    std::string whatami();
};

#endif // FIELDELEMENT_H
