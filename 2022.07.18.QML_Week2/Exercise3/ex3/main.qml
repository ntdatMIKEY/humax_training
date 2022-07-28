import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3
import customStaffList 1.0

//FileDialog {
//    id: fileDialog
//    title: "Please choose a file"
//    folder: shortcuts.home
//    onAccepted: {
//        console.log("You chose: " + fileDialog.fileUrls)
//        Qt.quit()
//    }
//    onRejected: {
//        console.log("Canceled")
//        Qt.quit()
//    }
//    Component.onCompleted: visible = true
//}


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Staff manage")


    Rectangle {
        id: menuw
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
                Action {
                    text: "&Quit and Save"
                    onTriggered: {
                        staffList.saveToFile();
                        console.log("write done")
                        Qt.quit()
                    }
                }
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
                    id: roletemp
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
                    anchors.top: roletemp.bottom
                    Text {
                        text: "ADD"
                        font.pixelSize: 15
                    }
                    onClicked: {
                        staffList.addStaff(nameInput.text, parseInt(ageInput.text), roleInput.currentIndex);

                    }
                }
            }
        }
    }


    Rectangle {
        id: listFrame
        anchors.top: menuw.bottom

        property alias chosenStaff: lv.currentIndex
        onChosenStaffChanged: {console.log(chosenStaff); }
        width: 320
        height: 480
        Text {
            id: temptxt
            text: "Team Members"
        }
        Rectangle {
            width: 300; height: 400
            anchors.top: temptxt.bottom
            border.color: "lightgrey"

            ListView {
                id: lv
                x: 10; y: 10
                anchors.fill: parent
                clip: true
                model: staffList/*.rowCount()*/
                delegate: Component {
                    Rectangle {
                        id: staffDelegate
                        width: 292; height: 50
                        border.color: index === lv.currentIndex ? "grey" : "white"
//                        property var cs: staffList.getStaff(modelData)

                        //role rectangle
                        Rectangle {
                            id: roleRect
                            height: parent.height - 2; width: height
                            anchors {
                                left: parent.left
                                verticalCenter: parent.verticalCenter
                            }

                            color: {
                                switch(parseInt(model.role)) {
                                case 0: return "red";
                                case 1: return "green"
                                case 2: return "blue"
                                case 3: return "yellow"
                                default: return "red"
                                }

                            }
                        }
                        //name field
                        Rectangle {
                            id: nameRect
                            x: 10
                            height: parent.height - 2; width: 180;
                            anchors {
                                left: roleRect.right
                                verticalCenter: parent.verticalCenter
                            }
                            color: "lightgrey"
                            Text {
                                anchors.verticalCenter: parent.verticalCenter
                                font {
                                    pixelSize: 15
                                    bold: true
                                }

                                text: model.name
                            }
                        }

                        //age field
                        Rectangle {
                            id: ageRect
                            height: parent.height - 2; width: height
                            anchors {
                                right: parent.right
                                verticalCenter: parent.verticalCenter
                            }
                            color: "lightgrey"
                            Text {
                                anchors.centerIn: parent
                                font {
                                    pixelSize: 15
                                    bold: true
                                }
                                text: parseInt(model.age)
                            }
                        }
                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                lv.currentIndex = index
                            }
                        }
                    }
                }
            }
        }

        StaffList {
            id: staffList
            onListChanged: {
                //staffList.loadFromFile();
                console.log(staffList.rowCount())
                staffList.saveToFile()
                lv.model = staffList

            }
        }


    }

    Rectangle {
        id: infoFrame
        anchors.top: menuw.bottom
        anchors.right: parent.right
        width: 320; height: 480
        property var cs: staffList.getStaff(listFrame.chosenStaff)
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
                Text { text: "Name: \t" + infoFrame.cs.name; font.pixelSize: 15 }
            }
            Rectangle {
                id: agetxt
                x: nametxt.x
                width: parent.width; height: 40
                anchors.top: nametxt.bottom
                Text { text: "Age: \t" + parseInt(infoFrame.cs.age); font.pixelSize: 15 }
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
                    id: cbRole
                    x: 80
                    width: 200; height: parent.height

                    currentIndex: parseInt(infoFrame.cs.role)
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
                    console.log("updated")
                    staffList.updateStaff(listFrame.chosenStaff, infoFrame.cs.name, infoFrame.cs.age, cbRole.currentIndex)
                    //staffList.listChanged()
                }
            }

            //Update button
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
                    console.log("deleted")
                    staffList.deleteStaff(listFrame.chosenStaff)
                }
            }
        }
    }



}
