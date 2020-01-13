import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    id: root

    Column {
        id: cols
        anchors.fill: parent
        anchors.margins: 5
        spacing: 3

        Rectangle {
            id: frame
            width: parent.width
            height: 25
            border.color: "gray"
            border.width: 1

            TextInput {
                id: txtPlain
                anchors.fill: parent
                anchors.margins: 4
                onTextChanged: {
                    txtEncoded.text = Qt.btoa(txtPlain.text)
                }
            }
        }
        Rectangle {
            id: frame2
            width: parent.width
            height: parent.height - (frame.height + cols.spacing)
            border.color: "gray"
            border.width: 1

            TextArea{
                id:txtEncoded
                anchors.fill: parent
            }
        }
    }
}
