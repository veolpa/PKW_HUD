import QtQuick

Item {
    property string time
    x:0
    y:0
    width: 50
    height: 20

    Text{
        id: time_text
        text: time
        //color: "#a6023b"
        color: "lightblue"
        anchors.fill: parent
        fontSizeMode: Text.Fit
        minimumPixelSize: 10;
        font.pixelSize: 72
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }
    onTimeChanged: {
        time_text.text = time;
    }
}
