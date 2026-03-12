import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.15

Item {
    // On donne à l'Item parent toute la taille disponible
    anchors.fill: parent

    Button {
        // 1. Centrage parfait
        anchors.centerIn: parent

        // 2. Taille personnalisée
        implicitWidth: 80
        implicitHeight: 80

        // Style et icône
        icon.source: "qrc:/icone_gui/add_light.png"
        icon.width: 40  // On agrandit aussi l'icône à l'intérieur
        icon.height: 40

        highlighted: true
        Material.accent: Material.DeepPurple

        onClicked: main.create_document()

    }
}
