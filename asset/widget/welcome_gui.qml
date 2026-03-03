import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

Item {

    RowLayout {
        spacing: 200
        anchors.centerIn: parent

        // Un bouton standard avec une icône
        Button {
            text: "Cree un document"
            highlighted: true
            Material.accent: Material.Blue
            Material.primary: Material.Indigo
            //icon.name: "document-save"
            onClicked: console.log("Fichier sauvé !")
        }

        Button {
            text: "Espace de travail"
            highlighted: true
            Material.accent: Material.Blue
            Material.primary: Material.Indigo
            //icon.name: "document-save"
            onClicked: {}
        }
    }
}
