import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    visible: true
    width: 320
    height: 480
    title: qsTr("Light Controller")

    Button {
        id: btON
        x: 43
        y: 205
        text: qsTr("ON")
        onClicked: controller.turnOn()
    }

    Button {
        id: btOFF
        x: 175
        y: 205
        text: qsTr("OFF")
        onClicked: controller.turnOff()
    }
}
