/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -i mylight_interface.h -p :mylight_interface.cpp ..\ex4_control\mylight.xml
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#include "mylight_interface.h"
/*
 * Implementation of interface class LocalMyLightInterface
 */

LocalMyLightInterface::LocalMyLightInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent)
    : QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
{
}

LocalMyLightInterface::~LocalMyLightInterface()
{
}
