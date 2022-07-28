import QtQuick 2.0

//Circle shape
Rectangle {
    id: circle
    visible: { _shape == _shapeCheck }

    width: 100; height: 100; radius: width
    //anchors.centerIn: parent

    color: _co
    border {
        color: "black"
        width: 3
    }

    readonly property int _shapeCheck: 1
    property int _shape: 1
    property color _co: "red"
    property int _num: 0

    Text {
        font.pixelSize: 30
        font.bold: true
        anchors.centerIn: parent
        text: _num.toString()
    }
}
