import QtQuick

Item {
    id : rearItem
    x:0
    y:0
    width: 500
    height: 350
    property bool is_visible: false
    //visible : is_visible
    Image {
        visible: is_visible
        id: rearViewPicture
        source: "rearview.png"
        sourceSize.width: parent.width
        sourceSize.height: parent.height
        fillMode: Image.PreserveAspectFit
    }
    onIs_visibleChanged: {
        rearItem.visible = is_visible;
    }
}
