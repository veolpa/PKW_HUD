import QtQuick

Item {
    property int cur_mileage : 0
    x: 10
    y: 140
    width: 80
    height: 50

    Rectangle{
        id: mileage_rec
        anchors.fill: parent
        color: "black"
        border.color: "#a6023b"

        Text{
            id: mileage_text
            text: cur_mileage +" meter"
            color: "lightblue"
            anchors.fill: mileage_rec
            fontSizeMode: Text.Fit
            minimumPixelSize: 10;
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }


    }
    onCur_mileageChanged:  {
        mileage_text.text = cur_mileage + " meter"
    }

}
