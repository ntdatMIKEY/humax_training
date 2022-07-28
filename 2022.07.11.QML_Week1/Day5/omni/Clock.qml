import QtQuick 2.15
import QtQuick.Window 2.15
import QtQml 2.15
import QtMultimedia 5.15
import QtQuick.Dialogs 1.1
import QtQml.Models 2.0
import QtQuick.Controls 2.0

Rectangle {
    // get time from Js
    property var dateTimeStr: new Date()
    property var dateStr: [Qt.formatDate(dateTimeStr, "yyyy"), Qt.formatDate(dateTimeStr, "MM"), Qt.formatDate(dateTimeStr, "dd")]
    property var timeStr: [Qt.formatTime(dateTimeStr, "hh"), Qt.formatTime(dateTimeStr, "mm"), Qt.formatTime(dateTimeStr, "ss")]

    /* dateInt
      [0]: year
      [1]: month
      [2]: date
      */
    /* timeInt
      [0]: hour
      [1]: minute
      [2]: second
      */
    property var dateInt: [parseInt(dateStr[0]), parseInt(dateStr[1]), parseInt(dateStr[2])]
    property var timeInt: [parseInt(timeStr[0]), parseInt(timeStr[1]), parseInt(timeStr[2])]

    //update after every 1 second
    signal updateChanged
    signal alarmChanged(int _h, int _m, bool _on)
    property var timeAlarm: [24, 60, false]

    state: "disable"

    onUpdateChanged: {
        //timeText.text = "Digital clock \n" + Qt.formatDateTime(new Date(), "yyyy-MM-dd") + "\n" + Qt.formatDateTime(new Date(), "hh:mm:ss");
        dateTimeStr = new Date()
        tickAudio.play()
        if(timeInt[2] === 0)
        {
            if(timeInt[0] === timeAlarm[0] && timeInt[1] === timeAlarm[1])
            {
                timeAlarm[2] = false
                console.log("ring ring");
                state = "alarming";
                messageDialog.open()
            }
        }
        if(timeInt[2] === 10)
        {
            messageDialog.close()
            state = "disable";

        }

        //update = false
    }
    onAlarmChanged: {
        timeAlarm[0] = _h;
        timeAlarm[1] = _m;
        timeAlarm[2] = _on;
    }

    //digital clock
    Rectangle {
        id: dClock
        width: parent.width/2
        height: parent.height/2

        Text {
            id: timeText
            anchors.centerIn: parent
            font.pixelSize: 20
            //text: "Digital clock \n" + Qt.formatDateTime(new Date(), "yyyy-MM-dd") + "\n" + Qt.formatDateTime(new Date(), "hh:mm:ss")
            text: "Digital clock \n" + dateStr[0] + "-" + dateStr[1] + "-" + dateStr[2] + "\n" + timeStr[0] + ":" + timeStr[1] + ":" + timeStr[2]
        }

    }

    //classic clock
    Rectangle {
        id: cClock
        anchors.right: parent.right
        width: parent.width/2
        height: parent.height
        color: "#ffe4c4"
        Image {
            anchors.centerIn: parent
            //anchors.fill: parent
            source: "img/main_clock.png"
            fillMode: Image.PreserveAspectFit

        }
        Rectangle {
            id: handHour

            width: 75; height: 8; radius: 10
            color: "black"
            x: parent.width/2; y: parent.height/2
            antialiasing: true
            layer.enabled: true // this screws things up

            transform: Rotation {
                origin.x: handHour.height/2; origin.y: handHour.height/2;
                angle: (timeInt[0] - 12) * 360 / 12 + 270 + 360/12 * timeInt[1]/60 + 360/12 * timeInt[2]/3600
            }

        }
        Rectangle {
            id: handMin

            width: handHour.width + 15; height: handHour.height / 2; radius: 10
            color: "black"
            x: parent.width/2; y: parent.height/2
            antialiasing: true
            layer.enabled: true // this screws things up

            transform: Rotation {
                origin.x: handMin.height/2; origin.y: handMin.height/2;
                angle: timeInt[1] * 360 / 60 + 270 + 360/60 * timeInt[2] / 60
            }
        }
        Rectangle {
            id: handSec

            width: handHour.width + 30; height: handHour.height / 4; radius: 10
            color: "black"
            x: parent.width/2; y: parent.height/2
            antialiasing: true
            layer.enabled: true // this screws things up

            transform: Rotation {
                origin.x: handSec.height/2; origin.y: handSec.height/2;
                angle: timeInt[2] * 360 / 60 + 270
            }
        }
    }

    //settings zone
    //alarm zone
    Rectangle {
        id: alarmSet
        width: parent.width/2
        height: parent.height/2
        y: parent.height/2
        border.color: "black"
        //border.width: 50

        //title
        Rectangle {
            width: parent.width;
            height: parent.height/3
            anchors.top: parent.top
            Text {
                anchors.centerIn: parent

                text: "Alarm clock"
                font.pixelSize: 25;
            }
        }

        //set time
        ComboBox {
            id: setHour
            width: parent.width*9/20; height: parent.height/3
            y: parent.height/3

            currentIndex: timeInt[0]
            //generate an array from 0->23
            model: Array.from({length: 24}, (_, index) => index);
            font.pixelSize: 30
            displayText: currentText
        }

        ComboBox {
            id: setMin
            width: parent.width*9/20; height: parent.height/3
            y: parent.height/3
            anchors.right: parent.right
            currentIndex: 59
            //generate an array from 0->59
            model: Array.from({length: 60}, (_, index) => index);
            font.pixelSize: 30
            displayText: currentText
        }
        Text {
            text: ":"
            anchors.centerIn: parent
            font.pixelSize: 30
        }

        //button
        Button {
            id: alarmButton
            text: "Set"
            font.pixelSize: 30
            width: parent.width; height: parent.height/3
            anchors.bottom: alarmSet.bottom
            //highlighted: true
            transitions: Transition {
                ColorAnimation { from: "#c0c0c0"; to: "cyan"; duration: 200 }
            }
            onClicked: {
                state = "alarmGood";
                messageDialog.open()
                alarmChanged(parseInt(setHour.currentValue), parseInt(setMin.currentValue), true);
            }
        }
    }

    Timer {
        id: timer1Sec
        interval: 1000; running: true; triggeredOnStart: false; repeat: true;
        onTriggered: {
            updateChanged() //= true;

        }
    }

    Audio {
        id: tickAudio
        source: "audio/tick1s.wav"
    }

    Audio {
        id: alarmAudio
        source: ""
    }

    MessageDialog {
        id: messageDialog
        title: "hehe boi"
        text: "Set alarm successfully"
        icon: StandardIcon.Information
        //modality: "NonModal"
        onAccepted: {
            //Qt.quit()
        }
        //Component.onCompleted: visible = true
    }
    states: [
        State {
            name: "disable"
            PropertyChanges {target: messageDialog; title: ""; visible: false}
        },
        State {
            name: "alarmGood"
            PropertyChanges {target: messageDialog; text: "Success"; icon: StandardIcon.Information; visible: true}
        },
        State {
            name: "alarming"
            PropertyChanges {target: messageDialog; text: "Wake up!!!"; icon: StandardIcon.NoIcon; visible: true}
        }
    ]
}
