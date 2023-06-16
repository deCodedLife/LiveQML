import QtQuick
import QtQuick.Controls.Material

import "../"

Rectangle {
    width: parent.width
    height: 64
    color: Material.accentColor
    visible: Settings.isHeaderVisible

    Item {
        anchors.fill: parent
        anchors.margins: 16

        Text {
            anchors.verticalCenter: parent.verticalCenter
            text: Settings.headerTitle
            color: Material.primaryTextColor
            font.pointSize: Settings.h1
        }
    }
}
