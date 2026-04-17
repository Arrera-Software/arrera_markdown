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
                highlighted: true
                Material.accent: Material.Indigo
                onClicked: main.open_web_page("https://arrera-software.fr/")
            }

            Item { Layout.fillWidth: true }

            Button {
                text: "Documentation"
                highlighted: true
                Material.accent: Material.Indigo
                onClicked: main.open_web_page("https://arrera-software.fr/")
            }

            Item { Layout.fillWidth: true }

            Button {
                text: "Code source"
                highlighted: true
                Material.accent: Material.Indigo
                onClicked: main.open_web_page("https://github.com/Arrera-Software/arrera_markdown")
            }
        }

        Button {
            text: "Retour a l'acceuil"
            highlighted: true
            Material.accent: Material.Indigo
            Layout.fillWidth: true
            Layout.preferredHeight: 40
            onClicked: main.back_about()
        }
    }
}
