#ifndef STYLE_H
#define STYLE_H

#include <QObject>
#include <QQmlEngine>
#include <QtGlobal>

class StyleClass : public QObject
{
    //The Q_OBJECT macro must appear in the private section of a class definition
    //that declares its own signals and slots
    //or that uses other services provided by Qt's meta-object system
    Q_OBJECT
public:
    explicit StyleClass(QObject *parent = nullptr);

    enum EnStyle {
        RED,
        GREEN,
        BLUE
    };

    //This macro registers an enum type with the meta-object system
    Q_ENUM(EnStyle)

    static void declareQml() {
        //registers new type "StyleClass" to QML system
        //QML file must import CustomQmlEnum 1.0 to use StyleClass
        qmlRegisterType<StyleClass>("CustomQmlEnum", 1, 0, "StyleClass");
    }

signals:

public slots:
};

#endif // STYLE_H
