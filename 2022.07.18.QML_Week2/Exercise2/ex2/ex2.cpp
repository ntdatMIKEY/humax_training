#include "ex2.h"

addingButton::addingButton(QObject *parent) :
    QObject(parent)
{
    m_shape = 1;
    m_color = "blue";
    m_number = 69;
}
