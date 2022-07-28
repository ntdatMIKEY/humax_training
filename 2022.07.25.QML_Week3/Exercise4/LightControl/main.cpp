// main.cpp
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "lightcontroller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    LightController controller;
    engine.rootContext()->setContextProperty("controller", &controller);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
