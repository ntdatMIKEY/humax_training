// main.cpp
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtDBus>
#include <QtQml>
#include "mylight.h"
#include "light_adaptor.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // Create new instance
    MyLight myLight;
    myLight.turnOn();
    engine.rootContext()->setContextProperty("myLight", &myLight);

    // Create interface adaptor
    new MyLightAdaptor(&myLight);

    // Connect to session bus
    QDBusConnection connection = QDBusConnection::sessionBus();
    connection.registerObject("/light", &myLight);
    connection.registerService("cong.service.light");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
