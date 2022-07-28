#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "test.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    // Create instance of test
    test m_test;

    // set context of application
    engine.rootContext()->setContextProperty("MyTest", &m_test);

    // load GUI
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    return app.exec();
}
