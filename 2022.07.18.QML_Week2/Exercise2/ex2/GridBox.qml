import QtQuick 2.15

Rectangle {
    width: 440; height: 440
    border {
        color: "black"
        width: 1
    }
    property alias gL: gridList

    Flickable {
        //anchors.fill: parent
        x: 20; y: 20
        width: 400; height: 400
        id: dafug
        contentHeight: gridShow.rows * 99
        contentWidth: 399
        //        topMargin: 20
        //        bottomMargin: 20
        //        leftMargin: 20
        //        rightMargin: 20
        contentY: ((gridShow.rows - 4) > 0) ? ((gridShow.rows - 4) * 99) : 0
        clip: true
        synchronousDrag: true
        Grid {
            id: gridShow
            columns: 4
            rows: gridList.count/4 + 1
            add: Transition {
                NumberAnimation { properties: "x,y"; easing.type: Easing.InOutQuad }
            }

            Repeater {
                id: rp
                model: gridList
                Product {pShape: model.shape; pColor: model.color; pNumber: model.num}
            }

            onAddChanged: {
                dafug.doSomeThing();
            }
        }

    }
    ListModel {
        id: gridList
    }


}
