/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -i chat_interface.h -p :chat_interface.cpp ..\sender\chat.xml
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#include "chat_interface.h"
/*
 * Implementation of interface class LocalReceiverInterface
 */

LocalReceiverInterface::LocalReceiverInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent)
    : QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
{
}

LocalReceiverInterface::~LocalReceiverInterface()
{
}

