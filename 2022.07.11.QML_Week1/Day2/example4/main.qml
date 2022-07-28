/*
  Example to demo QML components
    with C++ context

  Henry
  vqtrong@humaxdigital.com

  Number
  -

  */
import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    visible: true
    width: 400
    height: 400

    Text {
        x: 10
        y: 10
        text: "+"
        font.pixelSize: 50

        MouseArea {
            anchors.fill: parent
            onClicked: {
                // using property methods
                MyTest.temp++
            }
        }
    }

    Text {
        x: 100
        y: 10
        text: "-"
        font.pixelSize: 50

        MouseArea {
            anchors.fill: parent
            onClicked: {
                // using property methods
                MyTest.temp--

            }
        }

    }

    Text {
        x: 150
        y: 10

        text: "Reset"
        font.pixelSize: 50

        MouseArea {
            anchors.fill: parent
            onClicked: {
                // using slot
                MyTest.callReset();
            }
        }
    }

    Text {
        x: 300
        y: 10

        text: "Set"
        font.pixelSize: 50

        MouseArea {
            anchors.fill: parent
            onClicked: {
                // using slot
                MyTest.callSet(50);
            }
        }
    }


    Text {
        text: MyTest.temp.toString() //using notify, whenever MyTest.temp is change, text is updated via signal
        font.pixelSize: 50
        anchors.centerIn: parent
    }


    Connections {
        target: MyTest
        onShowAText:{
            console.log("Received a signal via Connection: index = ", index, "message = ", message)
        }
    }



}
