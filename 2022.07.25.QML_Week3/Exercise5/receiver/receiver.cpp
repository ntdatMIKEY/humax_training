#include "receiver.h"

Receiver::Receiver(QObject *parent)
{
    Q_UNUSED(parent);
    m_message = "Sir";
}

QString Receiver::message() const
{
    return m_message;
}

void Receiver::setMessage(QString _mess)
{
    m_message = _mess;
    Q_EMIT messageChanged();
}

void Receiver::receive(QString encoded_image)
{

    QByteArray _source = encoded_image.toUtf8();
//    QByteArray ba = QByteArray::fromBase64(_source);
////    QBuffer buffer(&ba);
////    QImage image = QImage::fromData(ba, "JPG");

//    QFile file;
//    QDir::setCurrent("D:/Training/2022.07.25.QML_Week3/Exercise5/receiver/img");
//    file.setFileName("receive.jpg");
//    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
//    file.write(ba);
//    file.close();
////    image.save(&buffer, "JPG");
//    qDebug() << ba;
//    setMessage("img/receive.jpg");
    QString resultString = QString::fromLatin1("data:image/png;base64,") + QString::fromLatin1(_source.toBase64().data());
    setMessage(resultString);

}

