import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3
import customStaffList 1.0

Rectangle {
    width: parent.width; height: 40
    //color: "grey"
    MenuBar {
        id: menu
        width: parent.width; height: parent.height
        Menu {
            title: "&File"
            Action {
                text: "&Add New Member ..."
                onTriggered: {
                    addingDialog.open()
                }
            }
            MenuSeparator { }
            Action { text: "&Quit" }
        }
        Menu {
            title: "&Help"
            Action { text: "&About" }
        }
    }
    Dialog {
        id: addingDialog
        //visible: true
        title: "Add a new member"

        contentItem: Rectangle {
            implicitWidth: 400
            implicitHeight: 180
            Rectangle {
                x: 10; y: 10
                width: parent.width; height: 40
                Text { text: "Name: \t"; font.pixelSize: 15 }
                TextInput {
                    id: nameInput
                    x: 80
                    text: "ABC"
                    font.pixelSize: 15
                }
            }
            Rectangle {
                x: 10; y: 50
                width: parent.width; height: 40

                Text { text: "Age: \t"; font.pixelSize: 15 }
                TextInput {
                    id: ageInput
                    x: 80
                    text: "0"
                    font.pixelSize: 15
                }
            }
            Rectangle {
                id: roletxt
                x: 10; y: 90
                width: parent.width; height: 40
                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    text: "Role: \t"
                    font.pixelSize: 15
                }
                ComboBox {
                    id: roleInput
                    x: 80
                    width: 200; height: parent.height
                    currentIndex: 1
                    model: ["BA", "Tester", "Developer", "Team leader"]
                    displayText: currentText
                }
            }
            Button {
                id: addBut
                width: parent.width/3; height: 40
                anchors.top: roletxt.bottom
                Text {
                    text: "ADD"
                    font.pixelSize: 15
                }
                onClicked: {
                    staffList.writeToJson(nameInput.text, parseInt(ageInput.text), roleInput.currentIndex);
                    staffList.listChanged();

                }
            }
        }
    }
    StaffList {
        id: staffList
        onListChanged: {
            readAllFromJson();
        }
    }
}
