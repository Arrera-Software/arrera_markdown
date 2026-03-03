import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

Item {

    Material.theme: Material.Light
    Material.accent: Material.BlueGrey
    Material.primary: Material.LightBlue

    RowLayout {
        spacing: 40
        anchors.centerIn: parent

        // Un bouton standard avec une icône
        Button {
            text: "Cree un document"
            //icon.name: "document-save"
            //onClicked: console.log("Fichier sauvé !")
        }

        Button {
            text: "Espace de travail"
            //icon.name: "document-save"
            //onClicked: console.log("Fichier sauvé !")
        }
    }
}
