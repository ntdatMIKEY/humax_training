import QtQuick 2.0
import QtQuick.Shapes 1.3

Item {
    id: product
    width: 100; height: 100
    //pShape = 0 box, = 1 circle, = 2 triangle
    property int pShape: 0
    property string pColor: "red"
    property int pNumber: 0


    //box shape
    Rectangle {
        id: box

        width: 100; height: 100; radius: 10
        //anchors.fill: parent

        border {
            color: "black"
            width: 3
        }

        color: product.pColor
        visible: { pShape === _shapeCheck }
        readonly property int _shapeCheck: 0

        Text {
            font.pixelSize: 30
            font.bold: true
            anchors.centerIn: parent
            text: product.pNumber.toString()
        }
    }

    //Circle shape
    Rectangle {
        id: circle

        width: 100; height: 100; radius: width
        //anchors.fill: parent

        border {
            color: "black"
            width: 3
        }
        color: product.pColor
        visible: { pShape === _shapeCheck }
        readonly property int _shapeCheck: 1

        Text {
            font.pixelSize: 30
            font.bold: true
            anchors.centerIn: parent
            text: product.pNumber.toString()
        }
    }


    //triangle shape
    Shape {
        id: triangle

        width: 100; height: 100
        //anchors.fill: parent

        visible: { pShape === _shapeCheck }
        readonly property int _shapeCheck: 2

        ShapePath {
            strokeStyle: ShapePath.SolidLine
            strokeColor: "black"
            strokeWidth: 3
            fillColor: product.pColor

            startX: triangle.width/2; startY: 0
            PathLine { x: 0; y: triangle.height}
            PathLine { x: triangle.width; y: triangle.height}
            PathLine { x: triangle.width/2; y: 0}
        }

        Text {
            font.pixelSize: 30
            font.bold: true
            anchors.centerIn: triangle
            text: product.pNumber.toString()
        }
    }
}


