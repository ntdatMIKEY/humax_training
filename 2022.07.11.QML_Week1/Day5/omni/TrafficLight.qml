import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQml.Models 2.0

Rectangle {
    id: tl
    width: 400
    height: 400
    border.color: "black"

    //traffic light
    Rectangle {
        id: light

        width: 150
        height: 400
        border.color: "black"
        color: "lightgrey"
        anchors.left: tl.left
        //state: "off"
        property int counter: 0

        //counter box
        Text {
            id: timeCount
            anchors.horizontalCenter: light.horizontalCenter
            y: 5
            text: light.counter
            font {
                bold: true
                pixelSize: 25
            }
        }

        //lights
        Grid {
            y: light.height / 5
            rows: 3; columns: 1; spacing: 10
            anchors.centerIn: parent
            Rectangle {
                id: red
                property int timesUp: 6
                width: 100; height: 100; radius: 100
                border.color: "black"
                color: "black"
            }
            Rectangle {
                id: yellow
                property int timesUp: 2
                width: 100; height: 100; radius: 100
                border.color: "black"
                color: "black"
            }
            Rectangle {
                id: green
                property int timesUp: 4
                width: 100; height: 100; radius: 100
                border.color: "black"
                color: "black"
            }
        }

        //states
        states: [
            State {
                name: "red"
                PropertyChanges { target: timeCount; color: "red"}
                PropertyChanges { target: light; counter: red.timesUp}
                PropertyChanges { target: red; color: "red"}
                PropertyChanges { target: yellow; color: "black"}
                PropertyChanges { target: green; color: "black"}
            },

            State {
                name: "yellow"
                PropertyChanges { target: timeCount; color: "yellow"}
                PropertyChanges { target: light; counter: yellow.timesUp}
                PropertyChanges { target: red; color: "black"}
                PropertyChanges { target: yellow; color: "yellow"}
                PropertyChanges { target: green; color: "black"}
            },

            State {
                name: "green"
                PropertyChanges { target: timeCount; color: "green"}
                PropertyChanges { target: light; counter: green.timesUp}
                PropertyChanges { target: red; color: "black"}
                PropertyChanges { target: yellow; color: "black"}
                PropertyChanges { target: green; color: "green"}
            },
            State {
                name: "black"
                PropertyChanges { target: timeCount; color: "black"}
                PropertyChanges { target: light; counter: 1}
                PropertyChanges { target: red; color: "black"}
                PropertyChanges { target: yellow; color: "black"}
                PropertyChanges { target: green; color: "black"}
            }

        ]

        //timer for light
        Timer {
            id: timer
            interval: 1000; running: true; triggeredOnStart : true; repeat: true
            onTriggered: {
                if(light.counter == 0)
                {
                    switch (light.state) {
                    default:
                        light.state = "red";
                        break;
                    case "red":
                        light.state = "green";
                        break;
                    case "green":
                        light.state = "yellow";
                        break;
                    case "yellow":
                        light.state = "red";
                        break;
                    }
                }
                light.counter--;
            }
        }
    }

    //set up zone
    Rectangle {
        id: settings
        width: 150; height: 150
        x: 200
        anchors {
            verticalCenter: tl.verticalCenter
            //horizontalCenter: tl.horizontalCenter
            margins: 5
        }
        border.color: "black"
        //border.width: 50
        ComboBox {
            id: settingsMenu
            width: parent.width; height: parent.height/3
            currentIndex: 0
            model: ["Red", "Yellow", "Green"]
            font.pixelSize: 15
            displayText: currentText + " time set"
        }

        Rectangle {
            color: "lightcyan"
            id: settingsInput
            width: parent.width; height: parent.height/3
            anchors.top: settingsMenu.bottom
            TextInput {
                id: settingsTxt
                text: "0"
                font.pixelSize: 20
                anchors {
                    fill: parent
                    horizontalCenter: parent.horizontalCenter
                    verticalCenter: parent.verticalCenter
                }
            }
        }

        Button {
            id: settingsButton
            text: "Set"
            font.pixelSize: 30
            width: parent.width; height: parent.height/3
            anchors.bottom: settings.bottom
            //highlighted: true
            transitions: Transition {
                ColorAnimation { from: "#c0c0c0"; to: "cyan"; duration: 200 }
            }
            onClicked: {
                var settingsTime = parseInt(settingsTxt.text, 10) + 1;
                if (isNaN(settingsTime)) { return 0; }
                switch (settingsMenu.currentIndex) {
                case 0:
                    red.timesUp = settingsTime;
                    break;
                case 1:
                    yellow.timesUp = settingsTime;
                    break;
                case 2:
                    green.timesUp = settingsTime;
                    break;
                default:
                    break;
                }
            }
        }
    }
}


