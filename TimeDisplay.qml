import QtQuick

Item {
    property string time
    x:0
    y:0
    width: 50
    height: 30

    Text{
        id: time_text
        text: time
        color: "#a6023b"
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
