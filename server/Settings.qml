pragma Singleton

import QtQuick
import QtQuick.Controls.Material

QtObject
{
    readonly property int h1: 24

    property int currentTheme: Material.Dark
    property int currentAccent: Material.Red

    property string headerTitle: ""
    property bool isHeaderVisible: true

    function hideHeader() {
        isHeaderVisible = false
    }

    function showHeader() {
        isHeaderVisible = true
    }

    property string currentPage: "Pages/HomePage.qml"
}
