// lightcontroller.h

#ifndef LIGHTCONTROLLER_H
#define LIGHTCONTROLLER_H

#include <QObject>
#include "mylight_interface.h"

class LightController : public QObject
{
    Q_OBJECT
public:
    explicit LightController(QObject *parent = nullptr);

public slots:
    void turnOn();
    void turnOff();

private:
    local::MyLight *theLight;
};

#endif // LIGHTCONTROLLER_H
