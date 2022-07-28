import QtQuick 2.0

//box shape
Rectangle {
    id: box
    visible: { _shape == _shapeCheck }

    width: 100; height: 100; radius: 10
    //anchors.centerIn: parent

    color: _co
    border {
        color: "black"
        width: 3
    }

    readonly property int _shapeCheck: 0
    property int _shape: 0
    property color _co: "red"
    property int _num: 0

    Text {
        font.pixelSize: 30
        font.bold: true
        anchors.centerIn: parent
        text: _num.toString()
    }
}
