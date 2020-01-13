import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0

Window {
    visible: true
    width: 500
    height: 500
    color: "white"
    title: qsTr("Hello World")

    Slider{
        id: slider
        width: parent.width
        value: 0
        from: 0
        to: 360
        enabled: true
        onValueChanged: {
            recCenter.rotation = slider.value

        }

    }

/*    MouseArea{
        anchors.fill: parent
        onClicked: {
            recCenter.width = parent.width / 4
            recCenter.height = parent.height / 4
        }
    }
*/
    Rectangle{
        id: recCenter
        width: parent.width / 2
        height: parent.height / 2
        color: "green"
        anchors.centerIn: parent
        Greenbox{
            id: recTopLeft
            anchors.right: recCenter.left
            anchors.bottom: recCenter.top
         }
        Greenbox{
            id: recLeft
            anchors.right: recCenter.left
            anchors.verticalCenter: recCenter.verticalCenter
         }
        Greenbox{
            id: recLeftBottom
            anchors.right: recCenter.left
            anchors.top: recCenter.bottom
         }
        Greenbox{
            id: recTopCenter
            anchors.horizontalCenter: recCenter.horizontalCenter
            anchors.bottom: recCenter.top
         }
        Greenbox{
            id: recTopRight
            anchors.left: recCenter.right
            anchors.bottom: recCenter.top
         }
        Greenbox{
            id: recRight
            anchors.left: recCenter.right
            anchors.verticalCenter: recCenter.verticalCenter
         }
        Greenbox{
            id: recRightBottom
            anchors.left: recCenter.right
            anchors.top: recCenter.bottom
         }
        Greenbox{
            id: recBottom
            anchors.horizontalCenter: recCenter.horizontalCenter
            anchors.top: recCenter.bottom
         }
        Greenbox{
            id: recMiddle
            anchors.centerIn: recCenter
         }
     }

   }

