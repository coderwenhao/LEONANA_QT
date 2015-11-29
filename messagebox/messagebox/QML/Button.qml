import QtQuick 2.0

Rectangle{
    id: root_object
    property string name: ""
    property string content: ""
    property alias contentColor: hint_text.color
    property alias contentFont: hint_text.font
    property string buttonColor: "lightblue"
    property string buttonDisableColor: "gray"
    property string controlFont: "Microsoft Yahei"
    property bool enabled: true
    property bool changeColorWhenDisable: true
    color: buttonColor
    signal buttonClicked(variant sender);

    MouseArea{
        id:mouse_area
        enabled: root_object.enabled
        hoverEnabled: root_object.enabled
        anchors.fill: parent
        onClicked: {
            root_object.buttonClicked(root_object);
        }
        onEntered: resetState()
        onExited: resetState()
        onReleased: resetState()
        onPressed: resetState()
    }

    Text{
        id: hint_text
        text: content
        anchors.centerIn: parent
        font.pixelSize: parent.height * 0.5
        font.family: controlFont
    }

    states:[
        State {
            name: "hovered"
            PropertyChanges {
                target: root_object
                color: Qt.lighter(buttonColor,1.1)
            }
        },
        State {
            name: "pressed"
            PropertyChanges {
                target: root_object
                color: Qt.darker(buttonColor,1.1)
            }
        },
        State {
            name: "disabled"
            when: root_object.enabled == false
            PropertyChanges {
                target: root_object
                color: buttonDisableColor
            }
        }
    ]

    function resetState()
    {
        if(root_object.enabled)
        {
            if(mouse_area.pressed)
                root_object.state = "pressed"
            else if(mouse_area.containsMouse)
                root_object.state = "hovered"
            else
                root_object.state = ""
        }
        else
        {
            root_object.state = "disabled"
        }
    }
}
