#ifndef EX4_H
#define EX4_H

#include <QObject>
#include <QDebug>

class ex : public QObject
{
    //The Q_OBJECT macro must appear in the private section of a
    //class definition that declares its own signals and slots
    //or that uses other services provided by Qt's meta-object system.
    Q_OBJECT

    //used to declare property in classes that inherit QObject
    Q_PROPERTY(int temp READ temp WRITE setTemp NOTIFY tempChanged)

public:
    ex(QObject *parent = 0);

    // getTemp
    int temp()
    {
        return m_temp;
    }

    // setTemp
    void setTemp(int _temp)
    {
        m_temp = _temp;
        qDebug() << "setTemp() is called";

        // Q_EMIT sends signal from c++ side to qml side
        // to notify change
        Q_EMIT tempChanged();
    }

public slots:

    void callReset()
    {
       m_temp = 69;
       qDebug() << "callReset() is called from C++";

       // send signal to notify change
       Q_EMIT tempChanged();

       // send signal to QML via signal
       Q_EMIT showAText(m_temp, "callReset");
    }

    void callSet(int _m_value)
    {
       m_temp = _m_value;
       qDebug() << "callSet() is called from C++";

       // send signal to notify change
       Q_EMIT tempChanged();

       // send signal to QML via signal
       Q_EMIT showAText(m_temp, "callSet");
    }

Q_SIGNALS:
    void tempChanged();
    void showAText(int index, const QString &message);

private:
   int m_temp;

};


#endif // EX4_H
