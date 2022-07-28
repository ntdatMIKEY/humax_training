import QtQuick 2.12
import QtQuick.Window 2.12
import CustomQmlEnum 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("exam3_using_cpp_enum")

    Rectangle {
        id: rect
        anchors.fill: parent

        property int style: 0
        color: toColor(style)

        MouseArea {
            anchors.fill: parent

            onClicked: {
                if (rect.style < 2) {
                    rect.style++;
                }
                else {
                    rect.style = 0;
                }
            }
        }

        Text {
            color: "white"
            font.bold: true
            font.pixelSize: 36
            anchors.centerIn: parent
            text: "Click on screen to change color"
        }
    }

    function toColor(style) {
        switch(style) {
        case StyleClass.RED:
            return "red"
        case StyleClass.GREEN:
            return "green"
        case StyleClass.BLUE:
            return "blue"
        default:
            return "red"
        }
    }
}
