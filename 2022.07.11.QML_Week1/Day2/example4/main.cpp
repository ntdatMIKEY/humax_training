#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "ex4.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    // Create instance of ex
    ex m_test;

    // set context of application
    // MyTest is used in QML file
    engine.rootContext()->setContextProperty("MyTest", &m_test);

    // load GUI
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    return app.exec();
}
