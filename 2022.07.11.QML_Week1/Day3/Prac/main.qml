import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 600
    height: 500
    visible: true
    title: qsTr("Prac")
    //color: "grey"

    //traffic light
    Component {
        id: myTL

        TrafficLight {
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
        }

    }



    Loader {
        id: myLoader
    }

    Component.onCompleted: {
        myLoader.sourceComponent = myTL
    }

}
