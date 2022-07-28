import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle {
    width: 320
    height: 480
    Text {
        id: txt
        text: "Information"
    }
    Rectangle {
        width: 300; height: 400
        anchors.top: txt.bottom
        border.color: "lightgrey"
        Rectangle {
            id: nametxt
            x: 10; y: 10
            width: parent.width; height: 40
            Text { text: "Name: \t" + "Mikey"; font.pixelSize: 15 }
        }
        Rectangle {
            id: agetxt
            x: nametxt.x
            width: parent.width; height: 40
            anchors.top: nametxt.bottom
            Text { text: "Age: \t" + 23; font.pixelSize: 15 }
        }
        Rectangle {
            id: roletxt
            x: agetxt.x; y: 180
            width: parent.width; height: 40
            Text {
                anchors.verticalCenter: roletxt.verticalCenter
                text: "Role: \t"
                font.pixelSize: 15
            }
            ComboBox {
                id: cb
                x: 80
                width: 200; height: parent.height

                currentIndex: 1
                model: ["BA", "Tester", "Developer", "Team leader"]
//                delegate: Text {
//                    text: model.roleName
//                    MouseArea {
//                        anchors.fill: parent
//                        onClicked: {
//                            cb.popup.close()
//                            cb.currentIndex = roleEnum
//                        }

//                    }
//                }
                displayText: currentText

//                background: Rectangle {
//                    implicitWidth: 150
//                    implicitHeight: 40
//                    color: {
//                        switch(cb.currentIndex) {
//                        case 0: return "red";
//                        case 1: return "green"
//                        case 2: return "blue"
//                        case 3: return "yellow"
//                        default: return "white"
//                        }
//                    }
//                    border.color: cb.pressed ? "grey" : "white"
//                    border.width: cb.visualFocus ? 2 : 1
//                    radius: 10
//                }

            }
//            ListModel {
//                id: roleModel
//                ListElement {
//                    roleEnum: 0
//                    roleName: "BA"
//                }
//                ListElement {
//                    roleEnum: 1
//                    roleName: "Tester"
//                }
//                ListElement {
//                    roleEnum: 2
//                    roleName: "Developer"
//                }
//                ListElement {
//                    roleEnum: 3
//                    roleName: "Team leader"
//                }
//            }
//            Component {
//                id: roleDelegate
//                Rectangle {
//                    id: cont
//                    width: 200; height: 40
//                    color: {
//                        switch(roleEnum) {
//                        case 0: return "red";
//                        case 1: return "green"
//                        case 2: return "blue"
//                        case 3: return "yellow"
//                        default: return "white"
//                        }
//                    }
//                    Text {
//                        x: 10
//                        anchors.verticalCenter: cont.verticalCenter
//                        font.pixelSize: 15
//                        text: roleName
//                    }
//                    MouseArea {
//                        anchors.fill: parent
//                        onClicked: {
//                            cb.popup.close()
//                            cb.currentIndex = roleEnum
//                        }

//                    }
//                }
//            }
        }

        //Update button
        Button {
            id: updateButton

            x: (parent.width/2 - width)/2; y: 300
            width: 100; height: 40
            Text {
                anchors.centerIn: parent
                font.pixelSize: 15
                text: "UPDATE"
            }
            onClicked: {

            }
        }

        Button {
            id: deleteButton

            x: parent.width/2 + updateButton.x; y: 300
            width: 100; height: 40
            Text {
                anchors.centerIn: parent
                font.pixelSize: 15
                text: "DELETE"
            }
            onClicked: {

            }
        }
    }
}
