import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
// 1. AJOUTER CET IMPORT
import QtQuick.Controls.Material 2.15

Rectangle {
    id: root
    width: 300
    height: 500

    Label {
        id: titleLabel
        text: "Arrera Markdown\nparamétre"
        font.pixelSize: 20
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        anchors {
            top: parent.top
            topMargin: 20
            horizontalCenter: parent.horizontalCenter
        }
    }

    Column {
        id: centerButtons
        spacing: 15
        anchors.centerIn: parent

        Button {
            text: "Généraux"
            width: 150
            highlighted: true
            Material.accent: Material.BlueGrey
        }

        Button {
            text: "Espace\nde travail"
            width: 150
            highlighted: true
            Material.accent: Material.BlueGrey
        }

        Button {
            text: "Template\nde document"
            width: 150
            highlighted: true
            Material.accent: Material.BlueGrey
        }
    }

    Button {
        id: backButton
        text: "Retour"
        highlighted: true
        Material.accent: Material.BlueGrey

        anchors {
            bottom: parent.bottom
            bottomMargin: 20
            horizontalCenter: parent.horizontalCenter
        }

        onClicked: main.back_setting()
    }
}
