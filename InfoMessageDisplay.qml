import QtQuick

Item {
    property string msg

    onMsgChanged: {
        text_display.text = msg;
    }



    Rectangle{
        anchors.fill: parent
        color: "transparent"
        Text {
            id: text_display
            anchors.fill: parent
            fontSizeMode: Text.Fit
            minimumPixelSize: 10;
            font.pixelSize: 72
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            color: "green"
            text: ""
        }
    }
}
