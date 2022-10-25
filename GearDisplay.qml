import QtQuick

Item {
    property int max_gears: 6
    property int cur_gear: 0
    x: 10
    y: 50
    width: 50
    height: 50

    Rectangle{
        id: gear_rec
        anchors.fill: parent
        color: "transparent"
        border.color: "green"
    }
    Text {
        id: gear_text
        anchors.fill: gear_rec
        fontSizeMode: Text.Fit
        minimumPixelSize: 10;
        font.pixelSize: 72
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        color: "green"
        text: ""
    }


    onCur_gearChanged: {

        if      (cur_gear === 0) gear_text.text = "leer";
        else if (cur_gear ===-1) gear_text.text = "R";
        else gear_text.text = cur_gear;
    }

}
