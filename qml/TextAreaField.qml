import QtQuick 2.10
import QtQuick.Controls 2.4

TextArea {
    id:root
    property alias textColor: rect.color
    property alias hAlign: root.horizontalAlignment
    property alias vAlign: root.verticalAlignment
    property bool clippedText: false
    property bool backgroundVisible: true
    property alias backgroundColor: rect.color
    property string tooltip: ""

    background: Rectangle {
        id: rect
    }

    selectByMouse: true
    ToolTip.text: root.tooltip
    ToolTip.visible: root.tooltip.length >0 && hovered
    textFormat: TextEdit.RichText
}
