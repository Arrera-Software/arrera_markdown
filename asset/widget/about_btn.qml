import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material

Item {
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 1


        RowLayout {
            Layout.fillWidth: true

            Button {
                text: "Site internet"
                Material.accent: Material.Blue
                Material.primary: Material.Indigo
            }

            Item { Layout.fillWidth: true }

            Button {
                text: "Documentation"
                Material.accent: Material.Blue
                Material.primary: Material.Indigo
            }

            Item { Layout.fillWidth: true }

            Button {
                text: "Code source"
                Material.accent: Material.Blue
                Material.primary: Material.Indigo
            }
        }

        Button {
            text: "Retour a l'acceuil"
            Material.accent: Material.Blue
            Material.primary: Material.Indigo
            Layout.fillWidth: true
            Layout.preferredHeight: 40
            onClicked: main.back_about()
        }
    }
}
