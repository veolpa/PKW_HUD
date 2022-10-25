import QtQuick

Item {
    property int cur_mileage:0
    x: 10
    y: 140
    width: 80
    height: 50

    Rectangle{
        id: mileage_rec
        anchors.fill: parent
        color: "transparent"
        border.color: "green"
    }
    Text{
        id: mileage_text
        anchors.fill: mileage_rec
        fontSizeMode: Text.Fit
        minimumPixelSize: 10;
        font.pixelSize: 72
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        color: "green"
        text: ""
    }
    onCur_mileageChanged:  {
        mileage_text: cur_mileage
    }

}
