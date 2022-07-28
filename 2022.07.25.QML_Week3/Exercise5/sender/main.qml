import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 480
    height: 640
    visible: true
    title: qsTr("Sender")
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
//        TextInput {
//            id: txtSend
//            font.pixelSize: 15
//            text: "123"
//        }
        Image {
            id: imgSend
            source: tx.source
            anchors.centerIn: parent
            width: parent.width - 5; height: width

        }
    }

    Button {
        id: prevBut
        width: 50;
        x: 100; y: 350
        text: "<"
        onClicked: {

        }
    }
    Button {
        id: nextBut
        width: 50;
        x: 300; y: 350
        text: ">"
        onClicked: {

        }
    }
    Button {
        id: sendBut
        anchors.horizontalCenter: parent.horizontalCenter; y: 450
        text: "Send"
        onClicked: {
            tx.send(imgSend.source)
        }
    }



}
