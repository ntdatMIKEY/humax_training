import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 1.4

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Box game")

    Rectangle {
        id: leftSide
        width: parent.width * 3 / 4; height: parent.height
        anchors.left: parent.left
        GridBox {
            id: gridBox
            objectName: "gridBox"
            anchors.centerIn: parent
        }
    }

    Rectangle {
        id: rightSide
        width: parent.width * 1 / 4; height: parent.height
        anchors.right: parent.right
        Rectangle {
            x: 10

            border.color: "black"
            Grid {
                id: menu
                rows: 6; columns: 1
                spacing: 15

                horizontalItemAlignment: Grid.AlignHCenter
                verticalItemAlignment: Grid.AlignVCenter
                ShapeMenu {
                    id: shapeMenu
                    onChoiceChanged: sampleView.setShape(shapeMenu.getShape())

                }

                SampleView {
                    id: sampleView
                    objectName: "sampleView"
                    sShape: shapeMenu.getShape()


                }

                Button {
                    id: genBut
                    width: 110; height: 50
                    text: "GENERATE"
                    onClicked: {
//                        timer1s.start()
//                        var n = 10
//                        while (timer1s.running !== false)
//                        {
//                            var _sh = Math.floor(Math.random() * 3);
//                            var _c = colorList[Math.floor(Math.random() * colorList.length)];
//                            var _n = Math.floor(Math.random() * 100);
//                            sampleView.setSample(_sh, _c, _n)
//                            //n--;
//                            timer100ms.start();
//                            while (timer100ms.running !== false) {console.log(timer100ms.running)}
//                        }
                        timer100ms.start()
                        shapeMenu.enabled = false
                        genBut.enabled = false

                    }
                }

                Button {
                    id: addCppBut

                    width: 110; height: 50
                    text: "Add by Cpp"
                    onClicked: {
                        cppBut.addItem(sampleView.sShape, sampleView.sColor, sampleView.sNumber);

                        gridBox.gL.append({"shape": cppBut.shape, "color": cppBut.color, "num": cppBut.number});
                    }
                }

                Button {
                    id: addQmlBut

                    width: 110; height: 50
                    text: "Add by Qml"
                    onClicked: {
                        gridBox.gL.append({"shape": sampleView.sShape, "color": sampleView.sColor, "num": sampleView.sNumber})
                    }


                }

                Button {
                    id: clearBut

                    width: 110; height: 50
                    text: "CLEAR"
                    onClicked: {
                        gridBox.gL.clear()
                    }

                }
            }
        }
    }

    Timer {
        id: timer100ms
        property int count: 0
        interval: 50; running: false; repeat: true; triggeredOnStart: false;
        onTriggered: {
            var _sh = Math.floor(Math.random() * 3);
            var _c = Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
            var _n = Math.floor(Math.random() * 100);
            sampleView.setSample(_sh, _c, _n)
            count++
            if(count >= 1000/interval)
            {
                count = 0
                shapeMenu.enabled = true
                genBut.enabled = true
                stop()
            }
        }
    }



}

