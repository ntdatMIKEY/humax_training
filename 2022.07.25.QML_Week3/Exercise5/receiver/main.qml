import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 480
    height: 640
    visible: true
    title: qsTr("Receiver")
    Text {
        id: title
        text: "My Image"
        x: 20; y: 10
        font.pixelSize: 10
    }
    Rectangle {
        y: 35//; y: 35
        border.color: "grey"
        width: 300; height: width
        anchors.horizontalCenter: parent.horizontalCenter
        Image {
            id: imgReceive
            source: rx.message
            anchors.centerIn: parent
            width: parent.width - 5; height: width

        }
    }

    Button {
        id: requestBut
        anchors.horizontalCenter: parent.horizontalCenter; y: 450
        text: "Request"
        onClicked: {
        }
    }
}
