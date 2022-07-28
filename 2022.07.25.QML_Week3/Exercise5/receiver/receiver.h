#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include <QFile>
#include <QByteArray>
#include <QImage>

#include "chat_adaptor.h"

class Receiver : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)

public:
    explicit Receiver(QObject *parent = nullptr);

    QString message() const;
    void setMessage(QString _mess);

signals:
    void messageChanged();

public slots:
    void receive(QString encoded_image);

private:
    QString m_message;
};

#endif // RECEIVER_H
