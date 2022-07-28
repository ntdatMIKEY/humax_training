import QtQuick 2.0
import QtQuick.Window 2.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("hello color")
    Rectangle {
        id: page
        width: 320; height: 480
        color: "lightgray"

        Text {
            id: helloText
            text: "Hello world!"
            y: 30
            anchors.horizontalCenter: page.horizontalCenter
            font.pointSize: 24; font.bold: true
        }

        Grid {
            id: colorPicker
            rows: 2
            columns: 3
            spacing: 5
            x: 4; anchors.bottom: page.bottom; anchors.bottomMargin: 4
            Repeater {
                model: ["red", "green", "blue", "yellow", "steelblue", "black"]
                Cell {
                    cellColor: modelData
                    onMyOnclicked: helloText.color = cellColor
                }
            }

        }
    }
}
