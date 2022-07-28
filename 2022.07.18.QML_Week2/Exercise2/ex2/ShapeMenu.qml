import QtQuick 2.0
import QtQml.Models 2.0
import QtQuick.Controls 2.0

Rectangle {
    id: shapeMenu
    width: 150; height: 50
    property int choice: cb.currentIndex
    ComboBox {
        id: cb
        anchors.fill: parent
        currentIndex: 0
        model: ["BOX", "CIRCLE", "TRIANGLE"]
        font.pixelSize: 15
        font.bold: true
        displayText: currentText
    }

    function getShape() { return choice }
}
