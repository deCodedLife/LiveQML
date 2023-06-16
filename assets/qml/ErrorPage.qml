import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Layouts

ApplicationWindow
{
    width: 420
    height: 760

    visible: true

    Material.theme: Material.Dark
    Material.accent: Material.Red

    title: qsTr("Hello World")

    x: Screen.width - 460
    y: (Screen.height / 2) - (height / 2)

    flags: Qt.WindowStaysOnTopHint

    ColumnLayout {
        anchors.fill: parent

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Server is unavailable now"
            color: Material.primaryTextColor
            font.pointSize: 24
            font.bold: true
        }
    }

}
