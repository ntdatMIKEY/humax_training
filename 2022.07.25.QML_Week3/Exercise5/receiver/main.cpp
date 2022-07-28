#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtDBus>
#include <QtQml>
#include "receiver.h"
#include "chat_adaptor.h"



int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // Create new instance
    Receiver rx;
    engine.rootContext()->setContextProperty("rx", &rx);

    // Create interface adaptor
    new ReceiverAdaptor(&rx);

    // Connect to session bus
    QDBusConnection connection = QDBusConnection::sessionBus();
    connection.registerObject("/chat", &rx);
    connection.registerService("cong.service.chat");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
