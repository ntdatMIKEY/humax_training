/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -p chat_interface.h: ..\sender\chat.xml
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef CHAT_INTERFACE_H
#define CHAT_INTERFACE_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface local.Receiver
 */
class LocalReceiverInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "local.Receiver"; }

public:
    LocalReceiverInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    ~LocalReceiverInterface();

    Q_PROPERTY(QString message READ message WRITE setMessage)
    inline QString message() const
    { return qvariant_cast< QString >(property("message")); }
    inline void setMessage(const QString &value)
    { setProperty("message", QVariant::fromValue(value)); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> receive(const QString &encoded_image)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(encoded_image);
        return asyncCallWithArgumentList(QStringLiteral("receive"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void messageChanged();
};

namespace local {
  typedef ::LocalReceiverInterface Receiver;
}
#endif