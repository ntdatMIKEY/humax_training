import QtQuick 2.0

Item {
    id: container
    property alias cellColor: rectangle.color //alias is like pointer in C
    signal myOnclicked(color cellColor)

    width: 40; height: 25

    Rectangle {
        id: rectangle
        border.color: "white"
        anchors.fill: parent
    }

    MouseArea {
        anchors.fill: parent
        onClicked:
        {
            container.myOnclicked(container.cellColor)
        }
    }
    onMyOnclicked: {
        console.log("my check")
    }

}
