#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    QQuickView *qQuickView = new QQuickView();
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    qQuickView->setSource(url);
    qQuickView->show();
    return app.exec();
}
