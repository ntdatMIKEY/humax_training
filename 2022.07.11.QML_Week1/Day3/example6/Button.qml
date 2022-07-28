import QtQuick 2.0

Rectangle {
    id: root
    width: 100
    height: 50
    state: 'normal'

    property var images: ["qrc:/btn_nor","qrc:/btn_prs","qrc:/btn_sel"]

    Image {
        id: bgImage
        anchors.fill: parent
    }

    Text {
        id: txt
        font.pointSize: 16
        color: "white"
        anchors.fill: parent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Timer {
        id: timer
        interval: 1000; running: false; repeat: false
        onTriggered: {
            if(root.state == 'pressed')
                root.state = 'selected';
        }

    }

    MouseArea {
        anchors.fill: parent
        onPressed: {
            if(root.state == 'normal'){
                root.state = 'pressed';
                timer.start();
            }
            else if(root.state == 'selected'){
                root.state = 'normal';
            }
        }

        onReleased: {
            if(root.state == 'pressed'){
                timer.stop();
                root.state = 'normal';
            }
        }
    }

    states: [
        State {
            name: "normal"
            PropertyChanges { target: bgImage; source: images[0]}
            PropertyChanges { target: txt; text: "Normal"}
        },

        State {
            name: "pressed"
            PropertyChanges { target: bgImage; source: images[1]}
            PropertyChanges { target: txt; text: "Pressed"}
        },

        State {
            name: "selected"
            PropertyChanges { target: bgImage; source: images[2]}
            PropertyChanges { target: txt; text: "Selected"}
        }
    ]
}
