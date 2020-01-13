import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import QtQuick.Dialogs 1.2

Window {
    id: window
    visible: true
    width: 300
    height: 300

    ColorDialog{
        id: colorDialog
        modality:  Qt.WindowModal
        title: "Chose a color"
        color: "green"
        onAccepted: {console.log("Accepted: " + color)}
        onRejected: {console.log("Rejected:" )}
    }
    FontDialog{
        id: fontDialog
        modality:  Qt.WindowModal
        title: "Chose a font"

        onAccepted: {console.log("Accepted: " + color)}
        onRejected: {console.log("Rejected:" )}
    }
    Row{
        Button{
            id: btnColor
            text: "Color"
            onClicked: colorDialog.open()
        }
        Button{
            id: btnFont
            text: "Font"
            onClicked: fontDialog.open()
        }
        TextField{
            id: txtText
            text: "Enter some text"
            width: 300
        }
     }
    Text {
        id: preview
        text: txtText.text
        anchors.centerIn: parent
        color: colorDialog.color
        font: fontDialog.font
    }


}
