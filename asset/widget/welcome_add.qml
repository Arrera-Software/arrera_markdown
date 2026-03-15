import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.15

Item {
    anchors.fill: parent

    // Le conteneur Row permet d'aligner les éléments horizontalement
    Row {
        // 1. On centre le conteneur (qui contient les deux boutons) au milieu de l'Item
        anchors.centerIn: parent

        // 2. C'est ici qu'on définit l'écart (en pixels) entre les boutons
        spacing: 30

        // --- PREMIER BOUTON (Existant) ---
        Button {
            implicitWidth: 80
            implicitHeight: 80

            icon.source: "qrc:/icone_gui/add_light.png"
            icon.width: 40
            icon.height: 40

            highlighted: true
            Material.accent: Material.DeepPurple

            onClicked: main.create_document()
        }

        // --- DEUXIÈME BOUTON (Nouveau) ---
        Button {
            implicitWidth: 80
            implicitHeight: 80
            icon.source: "qrc:/icone_gui/open_light.png"
            icon.width: 40
            icon.height: 40

            highlighted: true
            Material.accent: Material.DeepPurple

            onClicked: main.open_document_btn_welcome()
        }
    }
}
