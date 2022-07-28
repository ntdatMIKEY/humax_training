import QtQuick 2.15
import QtQuick.Window 2.15
import QtQml 2.15
import QtMultimedia 5.15
import QtQuick.Dialogs 1.1
import QtQml.Models 2.0
import QtQuick.Controls 2.0

//Classic clock and digital clock app

Window {
    width: 600
    height: 300
    visible: true
    title: qsTr("Clock")

    Clock {
        anchors.fill: parent
    }

}

