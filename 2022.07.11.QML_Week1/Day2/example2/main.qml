import QtQuick 2.15

/**
 * Ex2: QML signals and Handler
 */



Rectangle {
    id: left
    //size = [width, height]
    property var size: [[400, 500], [600, 700]]
    property var co: ["red", "blue"]

    width: size[0][0]
    height: size[0][1]
    color: co[0]

    property int counter: 0

    signal myClicked(/*int _w, int _h, int _c*/)
    Text {
        id: appearedText
        text: qsTr("fsdgsgfg")
        color: "white"
    }

    onMyClicked: {
        counter++
        var a = counter%2

        left.width = left.size[a][0]
        left.height = left.size[a][1]
        left.color = left.co[a]
        appearedText.text = "times" + counter.toString()
    }
    MouseArea {
        anchors.fill: parent
        onClicked: left.myClicked(/*700, 700, "blue"*/)
    }
}
