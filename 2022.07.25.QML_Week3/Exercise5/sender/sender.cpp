#include "sender.h"

Sender::Sender(QObject *parent) : QObject(parent)
{
    theRX = new local::Receiver("cong.service.chat", "/chat", QDBusConnection::sessionBus(), this);
    m_source = "img/traffic_light.jpg";
    m_image = QImage(m_source);

}

void Sender::send()
{
    QString _new_message = image2String();
    theRX->receive(_new_message);
}

const QImage &Sender::image() const
{
    return m_image;
}

void Sender::setImage(const QImage &newImage)
{
    if (m_image == newImage)
        return;
    m_image = newImage;
    emit imageChanged();
}


const QString &Sender::source() const
{
    return m_source;
}

void Sender::setSource(const QString &newSource)
{
    if (m_source == newSource)
        return;
    m_source = newSource;
    emit sourceChanged();
}

QString Sender::image2String()
{
    QByteArray image;
    QFile file;
    QDir::setCurrent("D:/Training/2022.07.25.QML_Week3/Exercise5/sender/img");
    file.setFileName("traffic_light.jpg");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    image = file.readAll();
    file.close();

    QString encoded = QString(image.toBase64());

    qDebug() << encoded;

    return encoded;
}
