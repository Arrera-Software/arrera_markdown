import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

Item {
    implicitWidth: 200
    implicitHeight: 600

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 15
        spacing: 15

        Button {
            text:"+"
            Layout.alignment: Qt.AlignHCenter
            highlighted: true
            Material.accent: Material.BlueGrey
            Material.primary: Material.BlueGrey
            onClicked: mainWindow.create_document()
        }

        Button {
            text:"E"
            Layout.alignment: Qt.AlignHCenter
            highlighted: true
            Material.accent: Material.BlueGrey
            Material.primary: Material.BlueGrey
            onClicked: mainWindow.view_espace()
        }


        Item {
            Layout.fillHeight: true
        }

        Button {
            text:"SETTING"
            Layout.fillWidth: true
            highlighted: true
            Material.accent: Material.BlueGrey
            Material.primary: Material.BlueGrey
            //onClicked: console.log("Action du bas")
        }
    }
}
