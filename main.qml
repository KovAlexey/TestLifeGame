import QtQuick 2.14
import QtQuick.Window 2.14
import MyItems 1.0

Window {
    visible: true
    width: 800
    height: 800
    color: "black"
    title: qsTr("Hello World")
    LifeWorldRenderItem{
        anchors.fill: parent
    }
}
