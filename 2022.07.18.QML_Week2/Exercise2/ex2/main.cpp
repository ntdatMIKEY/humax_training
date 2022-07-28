#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "ex2.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // Create instance of addingButton
    addingButton cppButton;
    // set context of application
    // cppBut is used in QML file
    engine.rootContext()->setContextProperty("cppBut", &cppButton);

    // load GUI
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));



    return app.exec();
}
