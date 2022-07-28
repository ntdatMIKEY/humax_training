import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 320
    height: 480
    title: qsTr("My Light")
    property string _on: "icons/light_on.png"
    property string _off: "icons/light_off.png"

    Image {
        id: light
        width: Math.min(parent.height, parent.width) * 0.8
        height: width
        anchors.centerIn: parent
        state: myLight.isOn ? "ON" : "OFF"
        states: [
            State {
                name: "ON"
                PropertyChanges { target: light; source: _on }
            },
            State {
                name: "OFF"
                PropertyChanges { target: light; source: _off }
            }
        ]
    }
}
