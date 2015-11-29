import QtQuick 2.0
import QtQuick.Window 2.0
import QtGraphicalEffects 1.0

Window {
    id:root
    flags: Qt.Dialog | Qt.WindowStaysOnTopHint
    modality:  mainwindow.messageMode ? Qt.NonModal　: Qt.ApplicationModal
    width: mainwindow.messageMode ? 360 : 600
    height: mainwindow.messageMode ? 150 : 260
    x: mainwindow.messageMode ? (Screen.width - 360) : 0
    y: mainwindow.messageMode ? 120 : 0
    color: mainwindow.messageMode ? "transparent" : "#88000000"
    property int selectId: 0
    property string fontFamily: "Microsoft Yahei"

    signal buttonClicked(int buttonId)

    function getIcon() {
        /*if(mainwindow.mode === "information")
            return "qrc:/IMAGE/IMAGE/information.png"
        else*/ if(mainwindow.mode === "warning")
            return "qrc:/IMAGE/IMAGE/warning.png"
        else if(mainwindow.mode === "ask")
            return "qrc:/IMAGE/IMAGE/ask.png"
        else if(mainwindow.mode === "error")
            return "qrc:/IMAGE/IMAGE/error.png"
        return ""
    }

    function selected(button_id)
    {
        selectId = button_id
        buttonClicked(selectId)
    }

    Rectangle {
        id: centerArea
        visible: !mainwindow.messageMode
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        width: parent.width; height: 260
        color: "#0044cc"

        Row {
            id: messageRow
            anchors.top: parent.top
            anchors.topMargin: 64
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 10

            Image {
                id: icon
                width: mainwindow.mode !== "information" ? 50 : 0; height: 50
                anchors.verticalCenter: parent.verticalCenter
                fillMode: Image.PreserveAspectFit
                source: mainwindow.mode !== "information" ? "" : getIcon()
            }

            Text {
                font.pixelSize: 24
                font.family: fontFamily
                height: 50
                anchors.verticalCenter: parent.verticalCenter
                verticalAlignment: Text.AlignVCenter
                color: "#666666"
                wrapMode: Text.Wrap
                text: mainwindow.message
            }
        }

        Row {
            id:buttonRow
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 64
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 15

            Button {
                width: 240; height: 40
                color: "lightblue"
                contentColor: "black"
                content: "确定"
                contentFont.family: fontFamily
                onButtonClicked: selected(1)
            }

            Button {
                width: 240; height: 40
                color: "lightblue"
                contentColor: "black"
                content: "取消"
                contentFont.family: fontFamily
                visible: mainwindow.canelButtonVisiable
                onButtonClicked: selected(2)
            }
        }
    }

    RectangularGlow {
        id: effect
        visible: msgArea.visible
        anchors.fill: msgArea
        glowRadius: 5
        spread: 0
        color: "#88000000"
        cornerRadius: 5
    }

    Rectangle {
        id: msgArea
        anchors.fill: parent
        anchors.leftMargin: 10
        anchors.topMargin: 10
        anchors.bottomMargin: 10
        anchors.rightMargin: 3
        visible: mainwindow.messageMode
        color: "#880044cc"

        Text {
            width: parent.width; height: parent.height
            y: (parent.height - contentHeight) / 6
            anchors.left: parent.left
            anchors.leftMargin: 18
            font.pixelSize: 24
            font.family: fontFamily
            color: "white"
            text: mainwindow.message
            elide: Text.ElideRight
            wrapMode: Text.WrapAnywhere
        }
    }
}
