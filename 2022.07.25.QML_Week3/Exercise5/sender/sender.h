#ifndef SENDER_H
#define SENDER_H

#include <QObject>
#include <QDebug>
#include <QImage>
#include <QFile>
#include <QByteArray>
#include "chat_interface.h"

class Sender : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QImage image READ image WRITE setImage NOTIFY imageChanged)
    Q_PROPERTY(QString source READ source WRITE setSource NOTIFY sourceChanged)
public:
    Sender(QObject *parent = nullptr);

    const QImage &image() const;
    void setImage(const QImage &newImage);


    const QString &source() const;
    void setSource(const QString &newSource);

    QString image2String();

public slots:
    void send();


signals:
    void imageChanged();

    void sourceChanged();

private:
    local::Receiver *theRX;
    QImage m_image;
    QString m_source;
};

#endif // SENDER_H
