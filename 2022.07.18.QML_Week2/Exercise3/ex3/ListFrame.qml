import QtQuick 2.15
import QtQuick.Controls 2.15
import customStaffList 1.0

Rectangle {
    property alias chosenStaff: lv.currentIndex
    width: 320
    height: 480
    Text {
        id: txt
        text: "Team Members"
    }
    Rectangle {
        width: 300; height: 400
        anchors.top: txt.bottom
        border.color: "lightgrey"

        ListView {
            id: lv
            x: 10; y: 10
            anchors.fill: parent
            clip: true

            currentIndex: 0
            model: staffList.rowCount()
            delegate: staffDelegate

        }

    }
    Component {
        id: staffDelegate
        Rectangle {
            width: 292; height: 50
            border.color: index === lv.currentIndex ? "grey" : "white"
            Grid {
                rows: 1; columns: 3
                spacing: 20
                verticalItemAlignment: Grid.AlignVCenter

                //role rectangle
                Rectangle {
                    width: 48; height: 48
                    color: {
                        switch(parseInt(staffList.getInfoAt(modelData, 0x0100 + 3))) {
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
                    width: 150; height: 48
                    color: "lightgrey"
                    Text {
                        anchors.verticalCenter: parent.verticalCenter
                        font {
                            pixelSize: 15
                            bold: true
                        }

                        text: staffList.getInfoAt(modelData, 0x0100 + 1)
                    }
                }

                //age field
                Rectangle {
                    width: 48; height: 48
                    color: "lightgrey"
                    Text {
                        anchors.centerIn: parent
                        font {
                            pixelSize: 15
                            bold: true
                        }
                        text: parseInt(staffList.getInfoAt(modelData, 0x0100 + 2))
                    }
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

    StaffList {
        id: staffList

    }


}

