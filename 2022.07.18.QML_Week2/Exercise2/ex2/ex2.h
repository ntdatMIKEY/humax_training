#ifndef EX2_H
#define EX2_H

#include <QObject>
#include <QDebug>
#include <QQmlComponent>
#include <QQuickView>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

class addingButton : public QObject
{
    //The Q_OBJECT macro must appear in the private section of a
    //class definition that declares its own signals and slots
    //or that uses other services provided by Qt's meta-object system.
    Q_OBJECT

    //used to declare property in classes that inherit QObject
    Q_PROPERTY(int shape READ shape WRITE setShape NOTIFY shapeChanged)
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(int number READ number WRITE setNumber NOTIFY numberChanged)



public:
    addingButton(QObject *parent = 0);

    int shape()
    {
        return m_shape;
    }

    // setTemp
    void setShape(int _sh)
    {
        m_shape = _sh;
        qDebug() << "setTemp() is called";

        // Q_EMIT sends signal from c++ side to qml side
        // to notify change
        Q_EMIT shapeChanged();
    }

    QString color()
    {
        return m_color;
    }

    // setTemp
    void setColor(QString _c)
    {
        m_color = _c;
        qDebug() << "setTemp() is called";

        // Q_EMIT sends signal from c++ side to qml side
        // to notify change
        Q_EMIT colorChanged();
    }

    int number()
    {
        return m_number;
    }

    // setTemp
    void setNumber(int _n)
    {
        m_shape = _n;
        qDebug() << "setTemp() is called";

        // Q_EMIT sends signal from c++ side to qml side
        // to notify change
        Q_EMIT numberChanged();
    }


public slots:
    void addItem(int _sh, QString _c, int _n)
    {
        m_shape = _sh;
        m_color = _c;
        m_number = _n;
    }

Q_SIGNALS:
    void shapeChanged();
    void colorChanged();
    void numberChanged();

private:
   int m_shape, m_number;
   QString m_color;
};

#endif // EX2_H
