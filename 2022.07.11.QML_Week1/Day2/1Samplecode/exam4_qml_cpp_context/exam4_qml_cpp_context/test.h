#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>

class test : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int temp READ temp WRITE setTemp NOTIFY tempChanged)

public:
    test(QObject *parent = 0);

    // temp
    int temp()
    {
        return m_temp;
    }

    void setTemp(int _temp)
    {
        m_temp = _temp;
        qDebug() << "setTemp() is called";

        // send signal to notify change
        Q_EMIT tempChanged();
    }

public slots:

    void callReset()
    {
       m_temp = 25;
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

#endif // TEST_H
