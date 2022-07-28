import QtQuick 2.0
import QtQuick.Controls 2.12

Rectangle {
    signal myTextChanged()
    signal myButtonClicked()
    property alias startText: txtInput.text

    TextInput {
        id: txtInput
        text: "Text input "
        anchors.horizontalCenter: parent.horizontalCenter
        y: 10
        color: "white"
        font.pixelSize: 30

        onTextChanged: {
            myTextChanged()
        }
    }

    Button {
        text: "Pick"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        onClicked: {
            myButtonClicked()
        }
    }

    function getText() {
        return txtInput.text
    }

    function setText(txt) {
        txtInput.text = txt
    }
}
