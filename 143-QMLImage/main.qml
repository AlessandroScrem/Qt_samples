import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0

Window {
    visible: true
    width: 550
    height: 550
    title: qsTr("Hello World")

    Slider{
        width: parent.width
        from: 0
        to: 360
        value: 0
        onValueChanged: {
            console.log(value)
            banana.rotation = value
        }
    }

    Image {
        id: tacocat
        source: "/files/images/tacocat.jpg"
        x: 25
        y: 25
    }
    AnimatedImage {
        id: banana
        source: "/files/images/banana.gif"
        anchors.centerIn: tacocat
        opacity: 0.5
    }
     /*
    Image {
        id: smile
        source: "https://upload.wikimedia.org/wikipedia/commons/8/85/Smiley.svg"
        onProgressChanged: {
            console.log("Smile Progress " + progress)
        }
    }
    */
}
