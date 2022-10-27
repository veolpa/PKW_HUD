import QtQuick
import volvera.de

Item {
    id: headingSlider
    property int heading_value

    Heading{
        id: headingClass
    }

    onHeading_valueChanged:{
        headingClass.heading=heading_value;
        headingLabel.text = headingClass.heading + " - " + headingClass.to_NEWS
    }

    Rectangle {
        id: headingRec1
        color: "transparent"
        width: 100
        height: 25
        border.color: "transparent"
        Text {
            id: headingLabel
            color: "lightblue"
            text:  headingClass.to_NEWS
            font.pointSize: 10
            anchors.fill: parent
            verticalAlignment: Text.AlignTop
            horizontalAlignment: Text.AlignHCenter
        }
    }

}

