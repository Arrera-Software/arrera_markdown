import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.15

Item {
    anchors.fill: parent

    ColumnLayout {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 10
        spacing: 10 // Espace entre les deux boutons

        Button {
            text: "Remettre à zéro les templates"
            Layout.fillWidth: true
            height: 40
            highlighted: true
            Material.accent: Material.BlueGrey
            Material.primary: Material.Indigo
            onClicked: main.reset_templates()
        }

        Button {
            text: "Retour à l'accueil"
            Layout.fillWidth: true
            height: 40
            highlighted: true
            Material.accent: Material.BlueGrey
            Material.primary: Material.Indigo
            onClicked: main.back_setting()
        }
    }
}
