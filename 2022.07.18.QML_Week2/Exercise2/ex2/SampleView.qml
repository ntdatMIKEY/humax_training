import QtQuick 2.0


Rectangle {
    id: sampleView
    width: 110; height: 110
    property int sShape: 0
    property string sColor: "red"
    property int sNumber: 1

    Product {
        anchors.centerIn: parent
        pShape: sShape
        pColor: sColor
        pNumber: sNumber
    }

    function setShape (_sh) {
        sShape = _sh;
    }

    function setSample (_sh, _c, _n) {
        sShape = _sh;
        sColor = _c;
        sNumber = _n;
    }


}
